/////////////////////////////////////////////////
//////////  Movimientos
/////////////////////////////////////////////////

// avanzar
void advance()
{
  servoR.write(177);
  servoL.write(0);
}

// retroceder
void move_back()
{
  servoR.write(0);
  servoL.write(180);
}

// girar a la derecha
void turnR()
{
  servoR.write(177);
  servoL.write(92);
}

// girar a la izquierda
void turnL()
{
  servoR.write(90);
  servoL.write(0);
}

// parar
void halt()
{
  servoR.write(90);
  servoL.write(92);
  for(i=0;i<10;i++) {
    move_back();
  }
}

