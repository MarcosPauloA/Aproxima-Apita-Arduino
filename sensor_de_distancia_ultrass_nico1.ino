// C++ code
//
int limiteDistancia = 200;
int cm = 0;
void acendeLedsQuandoObjetoAproximarDoSensor(int cm){
  if (cm > limiteDistancia){
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  if (cm < limiteDistancia){
    if (cm >= 150){
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
    }
    else if (cm < 150 && cm >= 100){
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
    }
    else if (cm < 100){
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
    }
  }
}
long lerDistanciaUltrasonica(int pinSensorUltrasonico = 7, int pinEchoUltrasonico = 6)
{
  pinMode(4, OUTPUT); //Led e alerta sonoro na porta 4
  pinMode(3, OUTPUT); //Led na porta 3
  pinMode(2, OUTPUT); //Led na porta 2
  pinMode(pinSensorUltrasonico, OUTPUT);  // Clear the trigger
  digitalWrite(pinSensorUltrasonico, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(pinSensorUltrasonico, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinSensorUltrasonico, LOW);
  pinMode(pinEchoUltrasonico, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(pinEchoUltrasonico, HIGH);
}
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  cm = 0.01723 * lerDistanciaUltrasonica(7, 6); // measure the ping time in cm
  Serial.print("Distancia do objeto ao sensor: ");
  Serial.print(cm);
  Serial.println("cm");
  acendeLedsQuandoObjetoAproximarDoSensor(cm);
}