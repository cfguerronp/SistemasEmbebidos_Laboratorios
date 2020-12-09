/*
 *          LABORATORIO 2
 *  Nombre: Carlos Guerron
 *  Fecha: 09/12/2020
 *  Tema: Realice un sistema domotico que cumpla las siguientes condiciones:
    Se tiene un reloj visualizado en una LCD donde se observa el horero y minutero. Sin embargo, por
    razones de simulacion, el minutero cambia su valor cada segundo y el horero en consecuencia, cada
    minuto.
    El sistema domotico cuenta con una interrupcion de encencido, seleccion de modo y pagado. Con
    otra interrupcion, se elige el modo de funcionamiento. El primer modo, es la activacion 4 luces de
    forma aleatoria con un minimo de activacion de 20 minutos. El segundo modo es el cambio de hora
    del reloj. Donde un conversor analogo digital cambia el horero y otro conversor el minutero. El
    tercer modo, es el sistema de seguridad con 4 sensores digitales que al activarse cualquiera de ellos.
    Enviaa mensajes seriales.
 */ 
#include<TimerOne.h>  // incluimos la librerira timer para realizar el enceddido de leds  
#include <LiquidCrystal.h>   // llamamos a la libreria liquidcrystal para el LCD

 LiquidCrystal lcd (13,12,11,10,9,8); // Inicializamos al lcd
 int puls1=6;
 int puls2=7;
 const int led1=7; //declaramos los pines de los leds
 const int led2=6;
 const int led3=5;
 const int led4=4;
 const int sensor1=A2; // declaramos los pines analogos como sensores
 const int sensor2=A3;
 const int sensor3=A4;
 const int sensor4=A5;
 int minutos;  //inicializamos a los minutos
 int horas;  //inicializamos a las horas
 int minU=0;
 int hrsU=0;

 int conteo=0;
 int conver; //variable para cad
 int conver2; //variable para cad
 int repe;
 int caso1=0; // sistema random
 int caso2=0;
 int caso3=0;
 int caso4=0;

 unsigned long timer=0; // variables de tamaño extendido para el almacenamiento de numeros.
 unsigned long timer2=0;

 int onOff=0; // variable interrupcion 0
 int cont; // variable interrupcion 1

void setup() {
  pinMode(puls1,INPUT); // declaramos los puls como entrada de dato
  pinMode(puls2,INPUT);
  pinMode(led1,OUTPUT); // declaramos a los leds como salida de dato
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(sensor1,INPUT); // declaramos los sensores como entrada de dato
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  Serial.begin(9600); // llamamos a nuestra terminal virtual
  lcd.begin(16,2);   //llamamos al lcd
  Timer1.initialize(1000000); // iniciamos al timer1
  Timer1.attachInterrupt(luces);  //llamamos al metodo luces para hacer el sistema aleotrio 
  attachInterrupt(0, encendido, LOW); // declaramos la interrupcion de encendido y apagado 
  attachInterrupt(1, modoFunc, LOW); // declaramos la interrucpion para el el modo de funcionamiento del sistema
  Serial.println("LABORATORIO 2");
  Serial.println("Carlos Guerron");
  caso1= random(1,5); // creamos el sistema random
  caso2= random(6,13);
  caso3= random(14,21);
  caso4= random(22,30);
}

void loop() {
  if(onOff==1 || onOff==2){
    timer2=(millis()/1000);
    if(timer!=timer2){
      timer=timer2;
      minU++;
      }
      reloj();
      impLCD();
      igualarReloj();
    }
    if(cont==3){
      if(digitalRead(sensor1)==HIGH){
        digitalWrite(led1,HIGH);
        Serial.println("Se ha activado el sensor 1");
        delay(500);
        }
        else
        digitalWrite(led1,LOW);
        
        if(digitalRead(sensor2)==HIGH){
          digitalWrite(led2,HIGH);
          Serial.println("Se ha activado el sensor 2");
          delay(500);
          }
          else
          digitalWrite(led2,LOW);
          
          if(digitalRead(sensor3)==HIGH){
            digitalWrite(led3,HIGH);
            Serial.println("Se ha activado el sensor 3");
            delay(500);
            }
            else
            digitalWrite(led3,LOW);
            
            if(digitalRead(sensor4)==HIGH){
              digitalWrite(led4,HIGH);
              Serial.println("Se ha activado el sensor 4");
              delay(500);
              }
              else
              digitalWrite(led4,LOW);
      }
}
void impLCD(){
  lcd.setCursor(3,1);
  lcd.print(hrsU);
  lcd.print(" ");
  lcd.setCursor(5,1);
  lcd.print(":");
  lcd.setCursor(7,1);
  lcd.print(minU);
  lcd.print(" ");
  
  }

void reloj(){  //metodo para el reloj
    if(minU==60){ //condicion para los minutos
    minU=00;
    minU++;  //se va incrementando cada segundo los minutos
    }
    if(hrsU==24)  // condicion para las horas
    hrsU=0;  


}
void igualarReloj(){
  if(cont==2){
    conver=analogRead(0);
    horas=map(conver,0,1023,0,24);
    hrsU=horas;
    conver2=analogRead(1);
    minutos=map(conver2,0,1023,0,60);
    minU=minutos;
    }
  }
  
void luces(){
  if(cont==1){
    conteo++;
    if(conteo==caso1){
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      }
      if(conteo==caso2){
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
      }
        if(conteo==caso3){
          digitalWrite(led1,LOW);
          digitalWrite(led2,HIGH);
          digitalWrite(led3,LOW);
          digitalWrite(led4,HIGH);
        }
            if(conteo==caso4){
              digitalWrite(led1,HIGH);
              digitalWrite(led2,HIGH);
              digitalWrite(led3,HIGH);
              digitalWrite(led4,HIGH);
              caso1=0;
              caso2=0;
              caso3=0;
              caso4=0;
            }
  }   
}   
void encendido(){
  switch(onOff){
    case 0:
    Serial.println("   LABORATORIO 2  ");
    Serial.println("ENCENDIDO");
    lcd.begin(16,2);
    lcd.setCursor(1,0);
    lcd.print("LAB 2 GuerronC");
    onOff++;
    break;
    case 1:
    Serial.println("Seleccione Modo");
    onOff++;
    break;
    case 2:
    Serial.println("APAGADO");
    cont=0;
    onOff=0;
    repe=0;
    minU=0;
    hrsU=0;
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    lcd.noDisplay();
    break;
    }
  }
  void modoFunc(){
    if(onOff==2){
      switch(cont){
        case 0:
        Serial.println("LUCES");
        cont++;
        break;
        case 1:
        Serial.println("IGUALAR RELOJ");
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        cont++;
        break;
        case 2:
        Serial.println("SENSORES");
        cont++;
        break;
        case 3:
        Serial.println("REINICIAR");
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        caso1=random(1,5);
        caso2=random(6,13);
        caso3=random(14,21);
        caso4=random(22,30);
        conteo=0;
        cont=0;
        break;
    
        }
      }
    }
