#include <PIDLoop.h>
#include <Pixy2SPI_SS.h>  
#include <Wire.h>
#include <EEPROM.h>

Pixy2SPI_SS pixyA;
Pixy2SPI_SS pixyB;

#define CS_PIXY_A 9
#define CS_PIXY_B 8
#define MAX_RANG 520         
#define ADC_SOLUTION 1024.0 

PIDLoop panLoop(400, 0, 400, true);
PIDLoop tiltLoop(500, 0, 500, true);
int posball = 0;
int section = 0;
int x, y, z;
float Nact = 0;
int norte = 0;  //175 355
int Rango = 25;
int r1 = -Rango;
int r2 = Rango;
int dif = 0;
int Velg = 58;
int Velg2 = 75;
int vel = 160;
int velini = vel;
int ori = 0;
int cerca = 0;
int sectionn = 0;
int yade = 0;
int difang = 0;
int VMBL = 0;
int VMAL = 0;
int kp = 0.9;  //base .9, 0.85, .95
int ab = 0;
int dir = 0;
int dirant = 0;
unsigned char high_byte, low_byte;
unsigned int angle16;

int sensity_t1, sensity_t2, sensity_t3;  
float VSUA, VSUD, VSUI;                  

const int SUI = A7;  
const int SUA = A8;
const int SUD = A9;
const int boton1 = A5;
char buf[64];
int32_t panOffset, tiltOffset;
int seccion;
int posant = 1;

int lin1 = 33;
int lin2 = 34;
int lin3 = 35;
int lin4 = 36;
int linres = 37;
int lin5 = 38;
int linea = 0;
//motores
int INAM1 = 7;
int INBM1 = 6;
int PWMM1 = 14;

int INAM2 = 5;
int INBM2 = 4;
int PWMM2 = 15;

int INAM3 = 3;
int INBM3 = 2;
int PWMM3 = 24;

int INAM4 = 1;
int INBM4 = 0;
int PWMM4 = 25;


void setup() {
Serial.begin(115200);
 Wire.begin();

  pinMode(CS_PIXY_A, OUTPUT);
  pinMode(CS_PIXY_B, OUTPUT);
  digitalWrite(CS_PIXY_A, HIGH);  
  digitalWrite(CS_PIXY_B, HIGH);  

  SPI.begin();  

  pixyA.init(CS_PIXY_A);  
  pixyB.init(CS_PIXY_B);  

      pinMode(boton1, INPUT);
     Wire.begin(); 
     if (digitalRead(boton1) == HIGH)
  {
    guardarnorte();
  }
   norte = EEPROM.read(0);
  norte = norte * 1.4117;

  //motores
  pinMode(INAM1, OUTPUT);
  pinMode(INBM1, OUTPUT);
  pinMode(PWMM1, OUTPUT);

  pinMode(INAM2, OUTPUT);
  pinMode(INBM2, OUTPUT);
  pinMode(PWMM2, OUTPUT);

  pinMode(INAM3, OUTPUT);
  pinMode(INBM3, OUTPUT);
  pinMode(PWMM3, OUTPUT);

  pinMode(INAM4, OUTPUT);
  pinMode(INBM4, OUTPUT);
  pinMode(PWMM4, OUTPUT);
  
  pinMode(SUI, INPUT);
  pinMode(SUA, INPUT);
  pinMode(SUD, INPUT);
  pinMode(lin1, INPUT);
  pinMode(lin2, INPUT);
  pinMode(lin3, INPUT);
  pinMode(lin4, INPUT);
  pinMode(lin5, INPUT);
  pinMode(linres, OUTPUT);
}

void loop() {

//leerultrasonico();
//leerbrujula2();
//orientar();
//camaraservo();
//leerlinea();
//camarafija();
guardarnorte();
//Adelante();
//Adelante();
}