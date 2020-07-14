//**** Arduino ile DC Motor Kontrolü ****//
/*   =======================
     ===                 ===
     === KOCAMAN DÜKKAN  ===
     ===     2020        === 
     =======================    
 *   
 *   by Umutcan YALÇIN
 */

/* Malzemeler:
 *  Arduino Uno ve Bağlantı Kablosu
 *  DC Motor
 *  BC547
 *  1N4001 Diyot
 *  Breadboard
 *  220 ohm direnç
 *  Jumper
 * 
 */
// Bağlantı şemasını dosya içerisindeki .png uzantılı dosyadan bulabilirsiniz.


int echoPin = 6;
int trigPin = 7;
long sure;
long mesafe;
int motorPin = 3;

void setup() {
  // put your setup code here, to run once:
 pinMode(echoPin, INPUT);//echoyu giriş pini olarak tanımladık. Çünkü ses dalgaları echo tarafından alınır.
 pinMode(trigPin, OUTPUT); //trig ise çıkış olarak tanımlandı. Çünkü ses dalgası trigerdan gönderilir.
 pinMode(motorPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

sure = pulseIn(echoPin, HIGH); // pulseIn HIGH veya LOW olarak kullanılabilir. Biz HIGH olarak kullanacağız. Ses dalgasının geri dönüş süresini ölçecek
mesafe = sure /29.1/2;

if (mesafe >= 20){
 analogWrite(motorPin,0);
 delay(100);
}
if (mesafe < 20){
 analogWrite(motorPin,255);
 delay(100);
}
}
