#include <Servo.h>

    Servo blastgate1;
    Servo blastgate2;
    Servo blastgate3;

    int bg1 = 2;
    int bg2 = 4;
    int bg3 = 7;

    bool bg1set = false;
    bool bg2set = false;
    bool bg3set = false;

    int Grad;

    //___________________VOID SETUP______________

    void setup() {

      pinMode(bg1, INPUT);
      pinMode(bg2, INPUT);
      pinMode(bg3, INPUT);

      pinMode(8, OUTPUT);		//Anschluss Signalleuchte Blast Gate 1
      pinMode(12, OUTPUT);		//Anschluss Signalleuchte Blast Gate 2
      pinMode(13, OUTPUT);		//Anschluss Signalleuchte Blast Gate 3

      bg1set = true;
      bg2set = true;
      bg3set = true;

      BG1(0);
      BG2(0);
      BG3(0);
    }

    //___________FUNKTION "schalten"________________

    void schalten (Servo blastgate, int PIN, int Winkel) {

      blastgate.attach(PIN);
      blastgate.write(Winkel);
      delay(500);
      blastgate.detach();

    }
  //___________FUNKTION "BlastGate1"___________________

    void BG1(int Stellung) {              //0=zu  1=auf
      if(bg1set && Stellung == 0) {
        Grad = 0;                         //Position in Grad
        digitalWrite(8, LOW);             //Signalleuchte aus
        schalten(blastgate1, 11, Grad);    //(Servo, Anschlusspin, Position)
        bg1set = false;
      }
      if(!bg1set && Stellung == 1) {
        Grad = 180;                         //Position in Grad
        digitalWrite(8, HIGH);             //Signalleuchte aus
        schalten(blastgate1, 11, Grad);    //(Servo, Anschlusspin, Position)
        bg1set = true;
      }
    }

  //___________FUNKTION "BlastGate2"___________________

    void BG2(int Stellung) {              //0=zu  1=auf
      if(bg2set && Stellung == 0) {
        Grad = 0;                         //Position in Grad
        digitalWrite(12, LOW);             //Signalleuchte aus
        schalten(blastgate2, 10, Grad);    //(Servo, Anschlusspin, Position)
        bg2set = false;
      }
      if(!bg2set && Stellung == 1) {
        Grad = 180;                         //Position in Grad
        digitalWrite(12, HIGH);             //Signalleuchte aus
        schalten(blastgate2, 10, Grad);    //(Servo, Anschlusspin, Position)
        bg2set = true;
      }    
    }

  //___________FUNKTION "BlastGate3"___________________

    void BG3(int Stellung) {              //0=zu  1=auf
      if(bg3set && Stellung == 0) {
        Grad = 0;                         //Position in Grad
        digitalWrite(13, LOW);             //Signalleuchte aus
        schalten(blastgate3, 9, Grad);    //(Servo, Anschlusspin, Position)
        bg3set = false;
      }
      if(!bg3set && Stellung == 1) {
        Grad = 180;                         //Position in Grad
        digitalWrite(13, HIGH);             //Signalleuchte aus
        schalten(blastgate3, 9, Grad);    //(Servo, Anschlusspin, Position)
        bg3set = true;
      }
  }


  //_____________VOID LOOP______________________
void loop() {
    while(digitalRead(bg1) == HIGH) {       //Blast Gate 1 oeffnen
      BG1(1);
      BG2(0);
      BG3(0);
}
    while(digitalRead(bg2) == HIGH) {       //Blast Gate 2 oeffnen
      BG2(1);
      BG1(0);
      BG3(0);
 }
    while(digitalRead(bg3) == HIGH) {       //Blast Gate 3 oeffnen
      BG3(1);
      BG1(0);
      BG2(0);
 }
}
