void leerlinea() {
  if (digitalRead(lin1) == 1 && digitalRead(lin2) == 1) {
    linea = 5;
  } else if (digitalRead(lin2) == 1 && digitalRead(lin3) == 1) {
    linea = 6;
  } else if (digitalRead(lin3) == 1 && digitalRead(lin4) == 1) {
    linea = 7;
  } else if (digitalRead(lin4) == 1 && digitalRead(lin1) == 1) {
    linea = 8;
  } else if (digitalRead(lin1) == 1) {
    linea = 1;
  } else if (digitalRead(lin2) == 1) {
    linea = 2;
  } else if (digitalRead(lin3) == 1) {
    linea = 3;
  } else if (digitalRead(lin4) == 1) {
    linea = 4;
  } else {
    linea = 0;
  }
  if (linea != 0) {
    Detener();
    delay(50);
    linea2();
  }
}
void linea2() {
  vel = 120;
  switch (linea) {
    case 1: // Adelante /
      Atras(); 
      delay(180); //160//
      break;

    case 2: //Derecha//
      Izquierda();
      delay(65); //0//
      break;

    case 3: ///Atras//
      Adelante();
      delay(150); //160//
      break;

    case 4: //Izquierda//
      Derecha();
      delay(65); //55//
    
      break;

    case 5: //noreste//
      Suroeste();
      delay(50); //40//
      break;

    case 6: // Sureste//
      Noroeste();
      delay(50); //40//
      break;

    case 7: //Suroeste//
      Noreste();
      delay(50); //40//
      break;

    case 8: //Noroeste//
      Sureste();
      delay(60); //50//
      break;
  }
  delay(100);
  Detener();
  digitalWrite(linres, 1);
  delay(60);
  digitalWrite(linres, 0);
  linea = 0;

  vel = velini;
}