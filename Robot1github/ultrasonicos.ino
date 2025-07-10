void ultrasonico() {

  VSUA = analogRead(SUA) * MAX_RANG / ADC_SOLUTION;
  VSUI = analogRead(SUI) * MAX_RANG / ADC_SOLUTION;
  VSUD = analogRead(SUD) * MAX_RANG / ADC_SOLUTION;
  // Serial.print("Sensor 1: ");
  //Serial.print(dist_t1, 0);a
  //Serial.println(" cm");

  // Si la pelota no es visible (seccion == 0)

  if (VSUA < 50) {
    Detener();
    pixyA.setServos(60 * 5.55, tiltLoop.m_command);
    //Serial.println("Obstáculo detectado a menos de 30 cm. Detenido.");
  } else if (VSUD < 50) {
    Sureste();
    pixyA.setServos(60 * 5.55, tiltLoop.m_command);
    //Serial.println("Obstáculo detectado a menos de 30 cm. Detenido.");
  } else {
    Atras();
    //Serial.println("No hay pelota. Retrocediendo...");
  }
}


// Serial.print("Sensor 1: ");
//Serial.print(dist_t1, 0);a
//Serial.println(" cm");

// Si la pelota no es visible (seccion == 0)

void ultraI() {
  VSUI = analogRead(SUI) * MAX_RANG / ADC_SOLUTION;
  if (VSUD < 50) {
    VSUA = analogRead(SUA) * MAX_RANG / ADC_SOLUTION;
    if (VSUA < 60) {
      Detener();
      pixyA.setServos(60 * 5.55, tiltLoop.m_command);
      //Serial.println("Obstáculo detectado a menos de 30 cm. Detenido.");
    } else {
      Atras();
    }

  } else {
    Derecha();
  }
}

void leerultrasonico() {
  VSUA = analogRead(SUA) * MAX_RANG / ADC_SOLUTION;
  VSUI = analogRead(SUI) * MAX_RANG / ADC_SOLUTION;
  VSUD = analogRead(SUD) * MAX_RANG / ADC_SOLUTION;
  Serial.print("VSUI ");
   Serial.print(VSUI);
  Serial.print("    ");
  Serial.print(" VSUA ");
  Serial.println(VSUA);
  Serial.print("VSUD ");
   Serial.print(VSUD);
}
void ultraI2() {
  VSUA = analogRead(SUA) * MAX_RANG / ADC_SOLUTION;
  
  if (VSUA < 80) {
    VSUI = analogRead(SUI) * MAX_RANG / ADC_SOLUTION;
    if (VSUI < 80) {
      Detener();
      pixyA.setServos(110 * 5.55, tiltLoop.m_command);
      //Serial.println("Obstáculo detectado a menos de 30 cm. Detenido.");
    } else {
      Izquierda();
      Serial.println("Izquierda");
      for ( int i = 0; i < 10; i++){
        pixyA.setServos(90 * 5.5, tiltLoop.m_command);
      } 
    }
  } else {
    Atras();
    Serial.println("Atras");
    for ( int i = 0; i < 10; i++){
      pixyA.setServos(90 * 5.5, tiltLoop.m_command);
    }
  }
}