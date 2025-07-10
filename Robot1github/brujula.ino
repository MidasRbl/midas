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
  difang = norte - Nact;
  Serial.print(Nact);
  Serial.println();

  return Nact;
}
/*int leerbrujula2() {

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
  
dif = (((Nact - norte + 540) % 360) - 180);
 */
/* Serial.print("Norte ");
  Serial.print(Norte);
  Serial.print("\t Nact..");
  Serial.print(Nact);
  Serial.print("\t dif:");
  Serial.println(dif); */
/*void orientar() {
 
 do {
    leerbrujula2(); 
    if (dif < r1) {
      GradosD();
      ori = 0;
      Serial.println("gder");

    } else if (dif > r2) {
      GradosI();
      ori = 0;
      Serial.println("gizq");
    } else {
      Serial.println("Detener");
      if (ori == 0)
      {
        
        Detener();
        delay(6);
        ori = 1;
      }
    }
  } while (ori == 0);
}
void orientar2() { 
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

void orientar() {
  Serial.println("Orientar");
  do  {
    if (ball == 1)
    {
      
      Serial.print("Camara20 ");
      Nact2 = obtcmpsdif20(norte);
    }
    else
    {
      
      Nact2 = obtcmpsdif2(norte);
      //digitalWrite(13, 0);
      Serial.print("Brújula sin ball: ");
    }
    Serial.println(Nact2);
    if (bruCam == 0)
    {
      if (Nact2 < N1)
      {
        GradosD();
        ori = 0;
      }
      else if (Nact2 > N2)
      {
        GradosI();
        ori = 0;
      }
      else
      {
        if (ori == 0)
        {
          Detener();
          delay(3);//era 3
          ori = 1;
          // ci = ci * 0.3;
          //cd = cd * 0.3;
        }
      }
    }
    else
    {
      if (Nact2 < N1)
      {
        GradosD();
        ori = 0;
      }
      else if (Nact2 > N2)
      {
        GradosI();
        ori = 0;
      }
      else
      {
        if (ori == 0)
        {
          Detener();
          delay(3);//era 3
          ori = 1;
          // ci = ci * 0.3;
          //cd = cd * 0.3;
        }
      }
    }

  } while (ori == 0);
}

void lecturacam() {

  //int digitalValue = digitalRead(PIXY_DIGITAL_PIN);
  int Aact = analogRead(PIXY_ANALOG_PIN);
  float voltage = Aact * (3.3 / 1023.0);
  difcam = Aact - 512;


  Serial.print("Valor Digital (Pin 1): ");
  //Serial.print(digitalValue);
  Serial.print(" | Valor Analógico (Pin 8): ");
  Serial.print(Aact);
  Serial.print(" | Voltaje: ");
  Serial.print(voltage, 2);
  Serial.println("V");



  delay(6);
}
void oricam() {
  do {
    lecturacam();
    if (difcam < rc1) {
      GradosI();
      Serial.println("gder");
      oric = 0;
    } else if (difcam > rc2) {
      GradosD();
      Serial.println("gizq");
      oric = 0;
    } else {
      if (oric == 0) {
        Detener();
        delay(6);
        oric = 1;
      }
    }
  } while (oric == 0);
}

void orientarCam() {
  do  {
    posCentral = analogRead(PIXY_ANALOG_PIN) / 13;
    dif = (40 - posCentral);
    Nact2 = dif;
    if (Nact2 < N1 * .5)
    {
      GradosD();
      ori = 0;
    }
    else if (Nact2 > N2 * .5)
    {
      GradosI();
      ori = 0;
    }
    else
    {
      if (ori == 0)
      {
        Detener();
        delay(3);//era 3
        ori = 1;
        // ci = ci * 0.3;
        //cd = cd * 0.3;
      }
    }
  } while (ori == 0);
}
int obtcmpsdif2(int x)
{
  bruCam = 0;
  dif = (((leerbrujula() - x + 540) % 360) - 180);
  return dif;
}
int obtcmpsdif20(int x)  //Limitar el valor leído de la Cámara con el rango
{ //90
  //Lectura de Camara

  ValinBall = digitalRead(PIXY_DIGITAL_PIN);

  if (ValinBall == 0)
  {
    CP = 0;
      ValinBall = 0;
      analogcam = analogcamant;
    /*if (CP < 100)
    {
      ValinBall = 1;
      CP = CP + 1;
      analogcam = analogcamant;
    }
    else
    {
      CP = 0;
      ValinBall = 0;
    }*/
  }
  else
  {
    analogcam = analogRead(PIXY_ANALOG_PIN);
  }

  analogcamant = analogcam;
  
  if (ValinBall == 1)
  {
    
    // Serial.println(" Orientar Camara ");

    //dif = (((brujula() - x + 540) % 360) - 180);           //digitalWrite(13, 1);
    //analogcam = analogRead(inBallanalog);
    
    //analogcamant = analogcam;
    
    posCentral = analogcam / 13; // 17 para Pixy 2.0    60 grados   //13 para Pixy 2.1 80 grados
   
    //Serial.print("Poscentral:  ");
    //Serial.println(posCentral);
    //imprimir poscentral
    
    if (posCentral > 16 && posCentral < 64) // 16 y 64  ,, 20 y 60
    {
      bruCam = 1;
      dif = 40 - posCentral;
      /*if (posCentral > 40)
      {
        dif = (35 - posCentral); //32
      }
      else
      {
        dif = (45 - posCentral); //32
      }*/

      /*if (dif > -25 && dif < 25)
        {
        bruCam = 1;
        }*/
    }
    else
    {
      
      CP = 0;
      bruCam = 0;
      dif = (((leerbrujula() - x + 540) % 360) - 180);
    }
  }
  else
  {
  
    CP = 0;
    bruCam = 0;
    //  Serial.println(" Orientar Brujula ");
    dif = (((leerbrujula() - x + 540) % 360) - 180);
    //digitalWrite(13, 0)
    //Serial.print("Brújula con ball: ");
  }
  return dif;

  //Serial.println(dif);
}
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