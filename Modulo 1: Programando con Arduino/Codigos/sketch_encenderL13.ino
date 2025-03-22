void setup() {
  //Declaracion de Variables
  //Aqui se trabaja que pin es de entrada/salida
  pinMode(13, OUTPUT); //Salida
}

void loop() {
  // Formamos Bucles
  digitalWrite(13, HIGH); //High = Voltaje 5
  delay(2000); //Se mantiene encendido 2000 milisegundos = 2 segundos
  digitalWrite(13, LOW); //Low= Apagar
  delay(2000); //1000 milisegundos = 1 segundos
  
}
