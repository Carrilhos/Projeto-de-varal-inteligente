//biblioteca 

#include <Stepper.h>


const int stepsPerRevolution = 200; // ajuste das etatapas por rotação // 300 mais velocidade menos torque

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); //declaração de objetos para controlar o motor

// configurações inicial 

void setup() {

  myStepper.setSpeed(110); // velocidade 
 
 } // fim setup


//loop

void loop() {
  myStepper.step(2048); // 2048 volta 180graus
 
 
 //myStepper.step(-stepsPerRevolution); // torque absurdo mas sem controle da rotação 
  delay(1000);

 
 } //fim loop
