#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
int Contrast=30;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define RX 10 //tx of blu
#define TX 9 //rx of blu
SoftwareSerial BluetoothSerial(RX,TX);


#define FLX A0
#define FLX1 A1
#define FLX2 A2
#define FLX3 A5


int a,b,c,d;
void setup() {
// put your setup code here, to run once:
analogWrite(6,Contrast);
Serial.begin(9600);
BluetoothSerial.begin(9600);
lcd.begin(16, 2);
lcd.print("device is ready");
delay(1000);
pinMode(FLX,INPUT);
pinMode(FLX1,INPUT);
pinMode(FLX2,INPUT);
pinMode(FLX3,INPUT);
BluetoothSerial.println("device is ready");
lcd.print("device is ready ");


}
void loop() {
// put your main code here, to run repeatedly:
a=analogRead(FLX);
b=analogRead(FLX1);
c=analogRead(FLX2);
d=analogRead(FLX3);
Serial.print("a");
Serial.print(a);
Serial.print(" b");
Serial.print(b);
Serial.print(" c");
Serial.print(c);
Serial.print(" d");
Serial.println(d);

if(a>20)
{
    BluetoothSerial.println("i need food");
lcd.clear();
lcd.print("i need food");
delay(3000);
}
else if(b>20)
{
    BluetoothSerial.println("i need water");
lcd.clear();
lcd.print("i need water");
delay(3000);
}
else if(c>20)
{
    BluetoothSerial.println("i need medicine");
lcd.clear();
lcd.print("i need medicine");

}
    

else if( d>127)
{ 
  BluetoothSerial.println("light on");
lcd.clear();
lcd.print("light on");

}
else if(a>40 && b>20)
{
    
lcd.clear();
lcd.print("fan off");
delay(3000);
}

delay(3000);
// delay(1000);
}
