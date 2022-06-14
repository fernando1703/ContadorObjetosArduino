#include<LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int fotocelda = 7;     
int valorFotocelda = 0; 
int led = 13;
int contador = 0; 
int total = 0;
String contador1;
String total1;
void(*resetFunc)(void) = 0;

void setup()
{
  Serial.begin(9600);            
  pinMode(fotocelda, INPUT); ; 
  lcd.begin(16,2);
  pinMode (led,OUTPUT);
  lcd.setCursor(0,0);            
  lcd.print("Elementos: 0"); 
}

void loop()
{
  if(Serial.available() > 0){
    if(Serial.read() == 'A'){
      resetFunc();
    }
  }
  
  valorFotocelda = digitalRead(fotocelda);  
  if(valorFotocelda!=1)
  {
    contador++; 
    total++;
    while(digitalRead(fotocelda)!=1) {
      delay(100);     
    }
    lcd.setCursor(11,0); 
    lcd.print(contador);
    contador1 = contador;
    total1 = total;
    Serial.println(contador1 + "-" + total1); 
    lcd.setCursor(0,1);
    lcd.println("Total: ");
    lcd.setCursor(7,1); 
    lcd.print(total);
    if(contador == 20){
      lcd.clear();
      lcd.setCursor(3,1); 
      lcd.println("CAJA LLENA   ");
      digitalWrite(led,1);
      delay (2000);           
      contador = 0;          
      lcd.clear();
      digitalWrite(led,0);
      lcd.setCursor(0,0);            
      lcd.print("Elementos: 0");
      lcd.setCursor(0,1);
      lcd.print("TOTAL: "); 
      lcd.setCursor(7,1);
      lcd.print(total);       
    }
  }
}
