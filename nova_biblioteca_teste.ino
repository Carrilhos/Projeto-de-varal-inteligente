#include <CustomStepper.h>
// Quatro primeiros paremetros definem os pinos. Os outros são opcionais de definem a ordem de acionamento das bobinas, passos por rotação, rotações por minuto e sentido da rotação
CustomStepper stepper(2, 3, 4, 5, (byte[]){8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001}, 4075, 10, CCW); // declaração de objeto
boolean rotate1 = false;
boolean rotatedeg = false;
boolean parar = false;

void setup()
{
  //Seta rpm
  stepper.setRPM(15);
  // Define passos por rotação
  stepper.setSPR(4075);
}

void loop()
{

  if (stepper.isDone() &&  rotate1 == false)
  {
    stepper.setDirection(CCW); // sentido de rotação do motor (CCV, CV e STOP)
    stepper.rotate(1);  // numero de giros que o motor dará. Se não for expecificado gira até ser parado.
    rotate1 = true;  // troca o valor de rotate1 e termina o if.
  }
  if (stepper.isDone() && rotate1 == true && rotatedeg == false)
  {
    stepper.setDirection(CW); // define direção da rotação do motor
    stepper.rotateDegrees(90); // Faz com que o motor gire um determinado numero de graus.
    rotatedeg = true;
  }
  if (stepper.isDone() && rotatedeg == true )
  {
    stepper.setDirection(STOP);
    
  }
  
  stepper.run();  // Faz com que o motor "starte"
  
}
