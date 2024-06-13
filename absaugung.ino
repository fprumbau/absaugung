#include <Servo.h>

    Servo blastgate1;
    Servo blastgate2;
    Servo blastgate3;

    int bg1 = 2;
    int bg2 = 4;
    int bg3 = 7;

    int Grad;

    //___________________VOID SETUP______________

    void setup() {

      pinMode(bg1, INPUT);
      pinMode(bg2, INPUT);
      pinMode(bg3, INPUT);

      pinMode(8, OUTPUT);		//Anschluss Signalleuchte Blast Gate 1
      pinMode(12, OUTPUT);		//Anschluss Signalleuchte Blast Gate 2
      pinMode(13, OUTPUT);		//Anschluss Signalleuchte Blast Gate 3

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
      if(Stellung == 0) {                 //Blast Gate 1 zu
        Grad = 0;                         //Position in Grad
        digitalWrite(8, LOW);             //Signalleuchte aus
      }
      if(Stellung == 1) {                 //Blast Gate oeffnen
        Grad = 360;                       //Position in Grad
        digitalWrite(8, HIGH);            //Signalleuchte an
      }
      schalten(blastgate1, 11, Grad);      //(Servo, Anschlusspin, Position)
    }

  //___________FUNKTION "BlastGate2"___________________

    void BG2(int Stellung) {              //0=zu  1=auf
      if(Stellung == 0) {                 //Blast Gate 1 zu
        Grad = 0;                         //Position in Grad
         digitalWrite(12, LOW);           //Signalleuchte aus
      }
      if(Stellung == 1) {                 //Blast Gate oeffnen
        Grad = 180;                       //Position in Grad
        digitalWrite(12, HIGH);           //Signalleuchte an
      }
      schalten(blastgate2, 10, Grad);     //(Servo, Anschlusspin, Position)
    }

  //___________FUNKTION "BlastGate3"___________________

    void BG3(int Stellung) {              //0=zu  1=auf
      if(Stellung == 0) {                 //Blast Gate 1 zu
        Grad = 0;                         //Position in Grad
        digitalWrite(13, LOW);            //Signalleuchte aus
      }
      if(Stellung == 1) {                 //Blast Gate oeffnen
        Grad = 180;                       //Position in Grad
        digitalWrite(13, HIGH);           //Signalleuchte an
      }
      schalten(blastgate3, 9, Grad);     //(Servo, Anschlusspin, Position)
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
