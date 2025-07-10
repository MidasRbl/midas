//multiplexores
int S0 = 0;
int S1 = 1;
int S2 = 2;
int S3 = 3;
int SIG1 = A3;
int SIG2 = A2;
//leds
int ledD = 9;
int ledF = 8;
int ledI = 7;
int ledA = 6;

int linea = 0;
int lineaA = 0;
int lineaB = 0;
int lineaC = 0;
int lineaD = 0;
int lineaF = 0;
int lineaE = 0;
int lineaG = 0;
int lineaH = 0;

int res = 0;
//comunicación
int lin1 = 18;  //41, 33
int lin2 = 20;  //43, 34
int lin3 = 21;  //45, 35
int lin4 = 19;  //47, 36
int lin5 = 23;
int linres = 22;  //49, 37y 38

int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v5 = 0;
int v6 = 0;
int v7 = 0;
int v8 = 0;
int v9 = 0;
int v10 = 0;
int v11 = 0;
int v12 = 0;
int v13 = 0;
int v14 = 0;
int v15 = 0;
int v16 = 0;
int v17 = 0;
int v18 = 0;
int v19 = 0;
int v20 = 0;
int v21 = 0;
int v22 = 0;
int v23 = 0;
int v24 = 0;
int v25 = 0;
int v26 = 0;
int v27 = 0;
int v28 = 0;
int v29 = 0;
int v30 = 0;
int v31 = 0;
int v32 = 0;
int x = 0;
int Muxv1[16] = { v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16 };
int Muxv2[16] = { v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32 };
//calibración
int Calv1 = 695;
int Calv2 = 820;
int Calv3 = 716;
int Calv4 = 724;
int Calv5 = 815;
int Calv6 = 780;
int Calv7 = 810;
int Calv8 = 826;
int Calv9 = 704;
int Calv10 = 795;
int Calv11 = 743;
int Calv12 = 808;
int Calv13 = 648;
int Calv14 = 2000;
int Calv15 = 644;
int Calv16 = 703;
int Calv17 = 709;
int Calv18 = 783;
int Calv19 = 645;
int Calv20 = 861;
int Calv21 = 735;
int Calv22 = 686;
int Calv23 = 683;
int Calv24 = 812;
int Calv25 = 752;
int Calv26 = 768;
int Calv27 = 2000;
int Calv28 = 683;
int Calv29 = 797;
int Calv30 = 772;
int Calv31 = 606;
int Calv32 = 716;
int Cal1[16] = { Calv1, Calv2, Calv3, Calv4, Calv5, Calv6, Calv7, Calv8, Calv9, Calv10, Calv11, Calv12, Calv13, Calv14, Calv15, Calv16 };
int Cal2[16] = { Calv17, Calv18, Calv19, Calv20, Calv21, Calv22, Calv23, Calv24, Calv25, Calv26, Calv27, Calv28, Calv29, Calv30, Calv31, Calv32 };
int pr1[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int pr2[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void setup() {

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(ledD, OUTPUT);
  pinMode(ledI, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledA, OUTPUT);

  pinMode(lin1, OUTPUT);
  pinMode(lin2, OUTPUT);
  pinMode(lin3, OUTPUT);
  pinMode(lin4, OUTPUT);
  pinMode(lin5, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(linres), reseteo, RISING);
  Serial.begin(115200);
}

void loop() {

  //imprimirvalor();
  //diferencia();
  linea8();
}


void seleccionarCanal(int canal) {
  digitalWrite(S0, canal & 0x01);
  digitalWrite(S1, (canal >> 1) & 0x01);
  digitalWrite(S2, (canal >> 2) & 0x01);
  digitalWrite(S3, (canal >> 3) & 0x01);
}

void imprimirvalor() {
  for (int canal = 0; canal < 16; canal++) {
    seleccionarCanal(canal);
    delayMicroseconds(5);

    Muxv1[canal] = analogRead(SIG1);  // Canal 1 a 16
    Muxv2[canal] = analogRead(SIG2);  // Canal 17 a 32
  }


  for (int i = 0; i < 16; i++) {
    if (i % 8 == 0) {
      Serial.println();
    }
    Serial.print("\tv");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(Muxv1[i]);
  }

  for (int i = 0; i < 16; i++) {
    if (i % 8 == 0) {
      Serial.println();
    }

    Serial.print("\tv");
    Serial.print(i + 17);
    Serial.print(": ");
    Serial.print(Muxv2[i]);
  }
  delay(200);
}
void diferencia() {
  for (int canal = 0; canal < 16; canal++) {

    seleccionarCanal(canal);
    delayMicroseconds(5);

    Muxv1[canal] = analogRead(SIG1);  // Canal 1 a 16
    Muxv2[canal] = analogRead(SIG2);  // Canal 17 a 32
    if (Muxv1[canal] > Cal1[canal]) {
      pr1[canal] = 1;
    } else {
      pr1[canal] = 0;
    }
    if (Muxv2[canal] > Cal2[canal]) {
      pr2[canal] = 1;
    } else {
      pr2[canal] = 0;
    }
  }

  for (int i = 0; i < 16; i++) {
    if (i % 8 == 0) {
      Serial.println();
    }
    Serial.print("\tp");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(pr1[i]);
  }

  for (int i = 0; i < 16; i++) {
    if (i % 8 == 0) {
      Serial.println();
    }

    Serial.print("\tp");
    Serial.print(i + 17);
    Serial.print(": ");
    Serial.print(pr2[i]);
  }
}


void linea8() {
  for (int canal = 0; canal < 16; canal++) {

    seleccionarCanal(canal);
    delayMicroseconds(5);

    Muxv1[canal] = analogRead(SIG1);  // Canal 1 a 16
    Muxv2[canal] = analogRead(SIG2);  // Canal 17 a 32
    if (Muxv1[canal] > Cal1[canal]) {
      pr1[canal] = 1;
    } else {
      pr1[canal] = 0;
    }
    if (Muxv2[canal] > Cal2[canal]) {
      pr2[canal] = 1;
    } else {
      pr2[canal] = 0;
    }
  }
  if (pr1[0] == 1 || pr1[1] == 1 || pr1[2] == 1 || pr1[3] == 1) {
    lineaA = 1;
    linea = 1;
  }
  if (pr1[4] == 1 || pr1[5] == 1 || pr1[6] == 1 || pr1[7] == 1) {
    lineaB = 1;
    linea = 2;
  }
  if (pr1[8] == 1 || pr1[9] == 1 || pr1[10] == 1 || pr1[11] == 1) {
    lineaC = 1;
    linea = 2;
  }
  if (pr1[12] == 1 || pr1[13] == 1 || pr1[14] == 1 || pr1[15] == 1) {
    lineaD = 1;
    linea = 3;
  }
  if (pr2[0] == 1 || pr2[1] == 1 || pr2[2] == 1 || pr2[3] == 1) {
    lineaE = 1;
    linea = 3;
  }
  if (pr2[4] == 1 || pr2[5] == 1 || pr2[6] == 1 || pr2[7] == 1) {
    lineaF = 1;
    linea = 4;
  }
  if (pr2[8] == 1 || pr2[9] == 1 || pr2[10] == 1 || pr2[11] == 1) {
    lineaG = 1;
    linea = 4;
  }
  if (pr2[12] == 1 || pr2[13] == 1 || pr2[14] == 1 || pr2[15] == 1) {
    lineaH = 1;
    linea = 1;
  }
  if (lineaA == 1 && lineaB == 1) {
    linea = 5;
  } else if (lineaB == 1 && lineaC == 1) {
    linea = 2;
  } else if (lineaC == 1 && lineaD == 1) {
    linea = 6;
  } else if (lineaD == 1 && lineaE == 1) {
    linea = 3;
  } else if (lineaE == 1 && lineaF == 1) {
    linea = 7;
  } else if (lineaF == 1 && lineaG == 1) {
    linea = 4;
  } else if (lineaG == 1 && lineaH == 1) {
    linea = 8;
  } else if (lineaH == 1 && lineaA == 1) {
    linea = 1;
  }

  if (linea != 0) {
    res = 1;
    switch (linea) {
      case 1:
        do {
          digitalWrite(ledF, 1);
          digitalWrite(lin1, 1);
        } while (res == 1);
        break;
      case 2:
        do {
          digitalWrite(ledD, 1);
          digitalWrite(lin2, 1);
        } while (res == 1);
        break;
      case 3:
        do {
          digitalWrite(ledA, 1);
          digitalWrite(lin3, 1);
        } while (res == 1);

        break;
      case 4:
        do {
          digitalWrite(ledI, 1);
          digitalWrite(lin4, 1);
        } while (res == 1);

        break;
      case 5:
        do {
          digitalWrite(lin2, 1);
          digitalWrite(lin1, 1);
          digitalWrite(ledF, 1);
          digitalWrite(ledD, 1);
        } while (res == 1);

        break;
      case 6:
        do {
          digitalWrite(lin2, 1);
          digitalWrite(lin3, 1);
          digitalWrite(ledA, 1);
          digitalWrite(ledD, 1);
        } while (res == 1);

        break;
      case 7:
        do {
          digitalWrite(lin4, 1);
          digitalWrite(lin3, 1);
          digitalWrite(ledA, 1);
          digitalWrite(ledI, 1);
        } while (res == 1);

        break;
      case 8:
        do {
          digitalWrite(lin4, 1);
          digitalWrite(lin1, 1);
          digitalWrite(ledF, 1);
          digitalWrite(ledI, 1);
        } while (res == 1);

        break;
      default:

        break;
    }
  }
  //delay(500);
}

void reseteo() {
  linea = 0;
  lineaA = 0;
  lineaB = 0;
  lineaC = 0;
  lineaD = 0;
  lineaE = 0;
  lineaF = 0;
  lineaG = 0;
  lineaH = 0;
  digitalWrite(ledF, 0);
  digitalWrite(ledD, 0);
  digitalWrite(ledA, 0);
  digitalWrite(ledI, 0);
  digitalWrite(lin1, 0);
  digitalWrite(lin2, 0);
  digitalWrite(lin3, 0);
  digitalWrite(lin4, 0);
  res = 0;
}
