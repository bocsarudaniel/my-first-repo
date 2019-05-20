#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>



#define SS_PIN 10
#define RST_PIN 9  
#define buzz 8
MFRC522 mfrc522(SS_PIN,RST_PIN);
LiquidCrystal lcd(1,2, 4, 5, 6, 7);


void setup() {
 lcd.begin(16,2);
 lcd.print("Camera goalaaaaaaaaa");
 SPI.begin();
 mfrc522.PCD_Init();
 noTone(buzz);
 }

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  String content = "";
  byte letter;
  for(byte i=0;i<mfrc522.uid.size;i++)
  {
        Serial.print(mfrc522.uid.uidByte[i] <0x10 ? "0" : " ");
        Serial.print(mfrc522.uid.uidByte[i],  HEX);
        content.concat(String(mfrc522.uid.uidByte[i] <0x10 ? "0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i],  HEX));
  }
  content.toUpperCase();
  if(content.substring(1) == "47 F7 6F 85"){
    tone(buzz, 500);
    delay(2000);
    lcd.clear();
    lcd.print("Acces Permis");
    noTone(buzz);
    delay (4000);
    lcd.clear();
    lcd.print("Puteti ocupa ca-");
    lcd.setCursor(2,1);
    lcd.print("mera 20 min");
    delay(4000);
    lcd.clear();
    lcd.print("Camera ocupata");
    delay(5000);
    lcd.clear();
  }
  else{
    lcd.clear();
    tone(buzz,500);
    lcd.print("Nu aveti autori-");
    lcd.setCursor(2,1);
    lcd.print("zatie");
    delay(500);
    noTone(buzz);
    delay(4000);
    lcd.clear();
  }
lcd.print("Camera goala");  

  
}
