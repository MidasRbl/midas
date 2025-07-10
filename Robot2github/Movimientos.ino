void revisar() {
  if (dir != dirant) {
    Detener();
    delay(3);
  }
  dirant = dir;
  difang = dif * kp;
  if (difang >= 0) {
    VMAL = vel;
    VMBL = vel - difang;
  } else {
    VMAL = vel + difang;
    VMBL = vel;
  }
}
void Adelante() {
    dir = 1;
  revisar();
  digitalWrite(INAM1, 1);
  digitalWrite(INBM1, 0);
  analogWrite(PWMM1, VMAL);
 
  digitalWrite(INAM2, 1);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, VMAL);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 1);
  analogWrite(PWMM3, VMAL);
  
  digitalWrite(INAM4, 0);
  digitalWrite(INBM4, 1);
  analogWrite(PWMM4, VMAL);
}
void Atras() {
   dir = 2;
  revisar();
 digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 1);
  analogWrite(PWMM1, vel);
 
  digitalWrite(INAM2, 0);
  digitalWrite(INBM2, 1);
  analogWrite(PWMM2, vel);
 
  digitalWrite(INAM3, 1);
  digitalWrite(INBM3, 0);
  analogWrite(PWMM3, vel);
  
  digitalWrite(INAM4, 1);
  digitalWrite(INBM4,0 );
  analogWrite(PWMM4, vel );
}
void Izquierda() { 
    dir = 3;
  revisar();
digitalWrite(INAM1, 1);
  digitalWrite(INBM1, 0);
  analogWrite(PWMM1, VMAL);
 
  digitalWrite(INAM2, 0);
  digitalWrite(INBM2, 1);
  analogWrite(PWMM2, VMBL);
 
  digitalWrite(INAM3, 1);
  digitalWrite(INBM3, 0);
  analogWrite(PWMM3, VMAL);
  
  digitalWrite(INAM4, 0);
  digitalWrite(INBM4, 1);
  analogWrite(PWMM4, VMBL );
  }
void Derecha(){
      dir = 4;
  revisar();
  digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 1);
  analogWrite(PWMM1, VMBL );
 
  digitalWrite(INAM2, 1);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, VMAL * 0.9);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 1);
  analogWrite(PWMM3, VMBL );
  
  digitalWrite(INAM4, 1);
  digitalWrite(INBM4, 0);
  analogWrite(PWMM4, VMAL* 0.9);
  
}
void Noreste(){
  digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 0);
  analogWrite(PWMM1, vel);
 
  digitalWrite(INAM2, 1);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, vel);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 1);
  analogWrite(PWMM3, vel);
  
  digitalWrite(INAM4, 0);
  digitalWrite(INBM4, 0);
  analogWrite(PWMM4, vel );
}
void Noroeste(){
  digitalWrite(INAM1, 1 );
  digitalWrite(INBM1, 0);
  analogWrite(PWMM1, vel);
 
  digitalWrite(INAM2, 0);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, vel);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 0);
  analogWrite(PWMM3, vel);
  
  digitalWrite(INAM4, 0);
  digitalWrite(INBM4, 1);
  analogWrite(PWMM4, vel );
}
void Sureste(){
  digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 1);
  analogWrite(PWMM1, vel);
 
  digitalWrite(INAM2, 0);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, vel);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 0);
  analogWrite(PWMM3, vel);
  
  digitalWrite(INAM4, 1);
  digitalWrite(INBM4, 0);
  analogWrite(PWMM4, vel );
}
void Suroeste(){
  digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 0);
  analogWrite(PWMM1, vel);
 
  digitalWrite(INAM2, 0);
  digitalWrite(INBM2, 1);
  analogWrite(PWMM2, vel);
 
  digitalWrite(INAM3, 1);
  digitalWrite(INBM3, 0);
  analogWrite(PWMM3, vel);
  
  digitalWrite(INAM4, 0);
  digitalWrite(INBM4, 0);
  analogWrite(PWMM4, vel );
}
void GradosD() {
  
  digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 1);
  analogWrite(PWMM1, Velg);
 
  digitalWrite(INAM2, 0);
  digitalWrite(INBM2, 1);
  analogWrite(PWMM2, Velg);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 1);
  analogWrite(PWMM3, Velg);
  
  digitalWrite(INAM4, 0);
  digitalWrite(INBM4, 1);
  analogWrite(PWMM4, Velg );

}
void GradosI() {
  
  digitalWrite(INAM1, 1);
  digitalWrite(INBM1, 0);
  analogWrite(PWMM1, Velg);
 
  digitalWrite(INAM2, 1);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, Velg);
 
  digitalWrite(INAM3, 1);
  digitalWrite(INBM3, 0);
  analogWrite(PWMM3, Velg);
  
  digitalWrite(INAM4, 1);
  digitalWrite(INBM4, 0);
  analogWrite(PWMM4, Velg );

}
void Detener() {
    digitalWrite(INAM1, 0);
  digitalWrite(INBM1, 1);
  analogWrite(PWMM1, 0);
 
  digitalWrite(INAM2, 1);
  digitalWrite(INBM2, 0);
  analogWrite(PWMM2, 0);
 
  digitalWrite(INAM3, 0);
  digitalWrite(INBM3, 1);
  analogWrite(PWMM3, 0);
  
  digitalWrite(INAM4, 1);
  digitalWrite(INBM4, 0);
  analogWrite(PWMM4, 0 );
}

void Zigda() {
  Derecha(); // derecha
  Serial.println("Derecha");
  for (int i = 0; i < 200; i++) {
   delay(1);
  }
leerlinea();

  Atras(); // atrás
  Serial.println("Atras");
  pixyA.setServos(60 * 5.55, tiltLoop.m_command);
  for (int i = 0; i < 300; i++) {
    delay(1);
  }
}

void Zigia() {
  Izquierda();
  Serial.println("Izquierda");
  for (int i = 0; i < 200; i++) {
    delay(1);
  }
leerlinea();

  Atras(); // sureste
  Serial.println("Atras");
  pixyA.setServos(120 * 5.55, tiltLoop.m_command);
  for (int i = 0; i < 300; i++) {
   delay(1);
  }
}