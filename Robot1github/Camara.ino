void Camara() {
  pixyA.ccc.getBlocks();  // Obtiene los bloques detectados por la Pixy 2

  if (pixyA.ccc.numBlocks) {  // Si hay bloques detectados
    for (int i = 0; i < pixyA.ccc.numBlocks; i++) {
      int x = pixyA.ccc.blocks[i].m_x;  // Coordenada X del centro del bloque
      int y = pixyA.ccc.blocks[i].m_y;  // Coordenada Y del centro del bloque

      // Dividir la imagen en 9 secciones
      // La imagen tiene un tamaño de 320x200 píxeles, por lo tanto cada sección es de aproximadamente 106x67 píxeles.

      // Sección en base a la coordenada x
      int sectionX = x / 106;  // Divide el ancho de la imagen (320 píxeles) en 3 partes
      // Sección en base a la coordenada y
      int sectionY = y / 67;  // Divide el alto de la imagen (200 píxeles) en 3 partes

      // Determinar la sección (1-9) con base en la división de la imagen
      section = sectionY * 3 + sectionX + 1;  // Fórmula para obtener la sección (1-9)
      
      // Imprimir la sección correspondiente
      Serial.print("Bloque en la sección: ");
      Serial.println(section);
    }
    if (section == 1) {
      Izquierda();
      Serial.println("Izquierda");

    } else if (section == 2) {
      Adelante();
      Serial.println("Adelante");

    } else if (section == 3) {
      Derecha();
      Serial.println("Derecha");

    } else if (section == 4) {
      Izquierda();
      Serial.println("Izquierda");

    } else if (section == 5) {
      Adelante();
      Serial.println("Adelante");

    } else if (section == 6) {
      Derecha();
      Serial.println("Derecha");

    } else if (section == 7) {
      Izquierda();
      Serial.println("Izquierda");

    } else if (section == 8) {
      Adelante();
      Serial.println("Adelante");

    } else if (section == 9) {
      Derecha();
      Serial.println("Derecha");
    }
  } else {
    section = 0;
    Atras();
    Serial.println("Atras");
  }
}
void camaraservo() {
   Serial.println(" Camaraservo ");
  static int i = 0;
  int j;
 digitalWrite(CS_PIXY_A, LOW);
/// no funciona ///
  // Obtener bloques detectados por Pixy
  pixyA.ccc.getBlocks();

  if (pixyA.ccc.numBlocks) {
Serial.println(" si Detecta ");
    // Invertimos la dirección izquierda-derecha
    panOffset = (int32_t)pixyA.ccc.blocks[0].m_x - 158;
    yade = (int32_t)pixyA.ccc.blocks[0].m_y;

    // Actualizar el control PID
    panLoop.update(panOffset);

    // Ajustar servos
    pixyA.setServos(panLoop.m_command, tiltLoop.m_command);

    // Ajustamos el cálculo de posball
    posball = 180 - panLoop.m_command / 5.55;
    if (posball >= 150) {//144
      seccion = 5;
    } else if (posball >= 120) {//108
      seccion = 4;
    } else if (posball >= 60) {//72
      seccion = 3;
    } else if (posball >= 30) {//36
      seccion = 2;
    } else {
      seccion = 1;
    }

    ab = 0;

  } else {
    Serial.println(" No Detecta ");
    ab++;
    if (ab >10) {
      seccion = 0;

      panLoop.reset();
      //tiltLoop.reset();
      pixyA.setServos(panLoop.m_command, tiltLoop.m_command);
      ab = 0;
    }
  }
  //Serial.println("---------------------------");
  Serial.print("Posición de la pelota: ");
  Serial.print(posball);
  Serial.print(" grados - Sección: ");
  Serial.println(seccion);
  Serial.println("---------------------------"); 
  ball = 1;  
  switch (seccion) {
    case 1:
      if (yade > 100) {//mayor cerca
        Sureste();
      } else {
        Derecha();
      }

      break;
    case 2:
      if (yade > 100) {
        Derecha();
      } else {
        Noreste();
      }

      break;
    case 3:
      Adelante();
      break;
    case 4:
      if (yade > 100) {
        Izquierda();
      } else {
        Noroeste();
      }

      break;
    case 5:
      if (yade > 100) {
        Suroeste();
      } else {
        Izquierda();
      }

      break;
    default:
    ball = 0;
      ultraI2();
      break;
  }
  digitalWrite(CS_PIXY_A, 1);
}
/*void camarafija() {

  digitalWrite(CS_PIXY_B, 0);
 
  pixyB.ccc.getBlocks();  // Obtiene los bloques detectados por la Pixy 2

  if (pixyB.ccc.numBlocks) {  // Si hay bloques detectados
    for (int i = 0; i < pixyB.ccc.numBlocks; i++) {
      int x = pixyB.ccc.blocks[i].m_x;  // Coordenada X del centro del bloque
      int y = pixyB.ccc.blocks[i].m_y;  // Coordenada Y del centro del bloque

      

      int sectionX = x / 160;  // Divide en 2 partes el ancho
      int sectionY = y / 100;  // Divide en 2 partes el alto

      // Determinar la sección (1-4) con base en la división
      int section = sectionY * 2 + sectionX + 1;  // (2 columnas)

      // Imprimir la sección correspondiente
      Serial.print("Bloque en la sección: ");
      Serial.println(section);
    }
    if (section==1){
Serial.println("seccion1");
Atras();
    }else if (section==2){
Serial.println("seccion2");
Atras();
    }
    else if (section==3){
Serial.println("seccion3");
Derecha();
    }
    else if (section==4){
      Serial.println("seccion4");
Izquierda();
    } else {
      ultraI2();
      Serial.println("ultrasonico");
    }


  }
    digitalWrite(CS_PIXY_B, 1);
}*/