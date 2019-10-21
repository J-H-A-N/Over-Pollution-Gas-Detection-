#define GAS_PIN1 A4
#define GAS_PIN2 A5
#define CAMBIO_SIGNIFICATIVO 3
int Resultado=0;

void setup()
{
  
  Serial.begin(9600);   // Initialize the serial port     
  delay(1000); 
  Serial.println("Over Pollution");
}
 int analogValue1 = -1;
 int analogValue2 = -1;
 
void loop(){

   int analogNew1 = analogRead(GAS_PIN1);
   int analogNew2 = analogRead(GAS_PIN2);

   if (abs(analogNew1-analogValue1) >= (10.23*CAMBIO_SIGNIFICATIVO)) {     //Correction Factor

    analogValue1 = analogNew1;
  }
  
   if (abs(analogNew2-analogValue2) >= (10.23*CAMBIO_SIGNIFICATIVO)) {     //Correction Factor
    analogValue2 = analogNew2;
  }
  
    Serial.write("");// Start sending data to bluetooth
    Serial.print("Contaminacion Sensor 1: "); //Pollution
    Serial.println(analogValue1);
    Serial.print("Contaminacion Sensor 2: "); //Cleaned pollution
    Serial.println(analogValue2);

    Resultado=analogValue1-analogValue2;

    Serial.print("---Aire Purificado--- ");
    Serial.println(Resultado);
    
    delay(2000);

    //Send data to bluetooth
    if(Serial.available()>0){
     int dato = Serial.read();  
    Serial.write(dato);  
    }
  
}
