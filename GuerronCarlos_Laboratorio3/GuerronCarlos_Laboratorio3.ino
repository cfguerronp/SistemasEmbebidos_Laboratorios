/*   UNIVERSIDAD TECNICA DEL NORTE
*        LABORATORIO 3
*     SISTEMAS EMBEBIDOS 
* JUEGO DE ATARI: CULEBRITA
* Nombre: Carlos Guerrón
* Fecha: 18/01/2021
*
*/
void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
}

void loop() {
  if(digitalRead(11)==LOW){
    delay(250);
    Serial.print("A");
    }
  if(digitalRead(10)==LOW){
    delay(250);
    Serial.print("B");
    }
  if(digitalRead(9)==LOW){
    delay(250);
    Serial.print("C");
    }
  if(digitalRead(8)==LOW){
    delay(250);
    Serial.print("D");
    }
  if(digitalRead(12)==LOW){
    delay(250);
    Serial.print("E");
    }
}
