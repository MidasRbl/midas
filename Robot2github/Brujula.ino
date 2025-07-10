int leerbrujula() {

  Wire.beginTransmission(0x60);
  Wire.write(0x02);
  Wire.endTransmission();

  Wire.requestFrom(0x60, 2);


  while (Wire.available() < 2);

  high_byte = Wire.read();
  low_byte = Wire.read();

  angle16 = high_byte;
  angle16 <<= 8;
  angle16 += low_byte;

  Nact = angle16 / 10;
  dif = norte - Nact;
  //Serial.print(Nact);
  //Serial.println();
  return Nact;
}
void leerbrujula2() {

  Wire.beginTransmission(0x60);
  Wire.write(0x02);
  Wire.endTransmission();

  Wire.requestFrom(0x60, 2);

  while (Wire.available() < 2);


  high_byte = Wire.read();
  low_byte = Wire.read();
  angle16 = high_byte;
  angle16 <<= 8;
  angle16 += low_byte;
  Nact = angle16 / 10;
  
//dif = (((Nact - norte + 540) % 360) - 180);
 
 /*Serial.print("Norte ");
  Serial.print(Norte);
  Serial.print("\t Nact..");
  Serial.print(Nact);
  Serial.print("\t dif:");
  Serial.println(dif); */
}
void orientar() {
 
 do {
    leerbrujula(); 
    if (dif < r1) {
      GradosD();
      ori = 0;
      //Serial.println("gder");

    } else if (dif > r2) {
      GradosI();
      ori = 0;
      //Serial.println("gizq");
    } else {
      //Serial.println("Detener");
      if (ori == 0)
      {
        
        Detener();
        delay(6);
        ori = 1;
      }
    }
  } while (ori == 0);
}
/*void orientar2() { 
  leerbrujula2();
  while (dif < r1 || dif > r2) {
    leerbrujula2();
    if (dif < r1) {
      GradosD();
      Serial.println("gder");

    } else if (dif > r2) {
      GradosI();
      Serial.println("gizq");
    }
  }
  Detener();
}*/
void guardarnorte()
{
  Serial.print("Calibrando:");
  for (int i = 0; i < 10; i++)
  {
    norte = leerbrujula();
    delay(100);
    Serial.println(norte);
  }
  delay(1000);
  for (int i = 0; i < 3; i++)
  {
    norte = leerbrujula();
    EEPROM.write(0, norte * .708);

    Serial.print("norteguardado:");
    Serial.println(norte);

  }
  Serial.print("norteguardado:");
  Serial.println(norte);
}