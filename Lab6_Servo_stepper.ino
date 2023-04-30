#include <Servo.h>

Servo myServo;    // crea un objeto Servo

int pos = 0;      // variable para almacenar la posición actual del servo

void setup() {
  myServo.attach(9);   // conecta el servo al pin 9
}

void loop() {
  // cambia la dirección del servo cada 5 segundos
  if (millis() % 5000 < 2500) {
    myServo.write(0);   // mueve el servo a 0 grados
  } else {
    myServo.write(180); // mueve el servo a 180 grados
  }

  // cambia la posición del servo suavemente cada 20 milisegundos
  for (int i = 0; i <= 180; i++) {
    pos = i;
    myServo.write(pos);   // mueve el servo a la posición actual
    delay(100);            // espera 20 ms antes de continuar
  }

  // cambia la velocidad del servo cada 5 segundos
  for (int i = 180; i >= 0; i--) {
    myServo.write(i);     // mueve el servo a la posición actual
    delay(100 * (180 - i)); // ajusta el tiempo de espera según la velocidad
  }
}
