
// The code consists of taking 10 samples of the analogue input A0,
// ordering them and discarding the highest and the lowest 
// and calculating the mean with the six remaining samples by converting this value to voltage in the variable pHVol, 
// then using the equation that we have calculated with the pH reference values 
// we convert pHVol to pHValue and send it to the serial port to see it in the serial monitor.


const int analogInPin = A0; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;
void setup() {
 Serial.begin(9600);
}
 
void loop() {
 for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
 Serial.print("sensor pH = ");
 Serial.println(phValue);
 
 delay(20);
}
