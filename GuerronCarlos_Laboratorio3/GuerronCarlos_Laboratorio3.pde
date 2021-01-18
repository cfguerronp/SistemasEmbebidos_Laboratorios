/*   UNIVERSIDAD TECNICA DEL NORTE
*        LABORATORIO 3
*     SISTEMAS EMBEBIDOS 
*JUEGO DE ATARI: CULEBRITA
* Nombre: Carlos Guerrón
* Fecha: 18/01/2021
*
*/
import processing.serial.*;

int filas = 44; // numero de filas
int columnas = 44; // numero de columnas
int bs=15; //tamaño de los cuadritos que la serpiente crecera
String dato;
ArrayList<Integer> posX = new ArrayList<Integer>(); // creamos un array list para que cuando la serpiente vaya creciendo, para pos x
ArrayList<Integer> posY = new ArrayList<Integer>(); //para pos Y

int direccion = 1; //para la direccion
int[] dx={0, 0, -1, 1}; //para la direccion de la serpiente, para ir de derecha e izquierda
int[] dy={-1, 1, 0, 0}; //para ir de arriba y abajo

int appleX; //para la manzana pos x
int appleY; //pos y
boolean gameOver = false; // para el fin de juego
Serial port;
void setup(){
  port= new Serial(this, "COM10",9600);
  size(660,660); //tamaño de la ventana
  posX.add(10); //empieza las pos x
  posY.add(10); //pos y
  frameRate(5); //para la velocidad de la serpiente
  appleX= (int)random(0, 44); //para poner en un lugar aleotorio la manzana, pos x
  appleY= (int)random(0, 44); //pos y
  
}
void draw(){
  background(#151513); //color de fondo 
  if(gameOver == true){ 
    fill(155); //mensaje para que presione tecla para jugar
    textSize(20);
    text("GAME OVER",300, height/3);
    text("PRESS START TO PLAY",250, height/2);
    appleX =-1; //para desaparecer la manzana
    appleY =-1;
    posX.clear();
    posY.clear();
    posX.add(-10);
    posY.add(-10);
  }else{
    stroke(#151513); //color de linea
    for(int i=0; i<filas; i++){
      line(0, i*bs, width, i*bs); //para dibujar las lineas horizontales en la ventana
    }
    for(int j=0; j<columnas; j++){
      line(j*bs, 0 ,j*bs, height); // para dibujar las lineas verticales
    }
  }
  key();
  move();
  eat();
  bordes();
  choqueSnake();
  drawApple();
  drawSnake();
}
void drawApple(){ //para dibujar la manzana
  fill(250, 3, 3);
  rect(appleX*bs, appleY*bs, bs, bs); //dibuja las manzanas
}
void drawSnake(){ //para dibujar la serpiente
  fill(#3EDE1B);
  for(int i=0; i<posX.size(); i++){
    rect(posX.get(i)*bs, posY.get(i)*bs, bs, bs); //para crear la serpiente y que crezaca cada ves que detecte otro valor
  }
}
void move(){ // para hacer que se mueva la serpiente
  posX.add(0, posX.get(0) + dx[direccion]); //para que se mueva la serpiente
  posY.add(0, posY.get(0) + dy[direccion]); //pos y
  posX.remove(posX.size()-1); //para ir borrando la serpiente y ver el tamaño real 
  posY.remove(posY.size()-1); //pos y
}
void eat(){ //para que cuando la serpiente coma aumente
  if((posX.get(0) == appleX) && (posY.get(0) == appleY)){ //condicion 
    appleX = (int)random(0,44); //numeros random que damos a la variable de la manzana
    appleY = (int)random(0,44); //pos y
    posX.add(posX.get(posX.size()-1)); // para coger la posicion en X y añadir a la serpiente
    posY.add(posY.get(posY.size()-1)); // para coger la posicion en Y y añadir a la serpiente
  }
}
void reset(){ //ponemos todos los valores en restaurar
  gameOver = false;
  posX.clear();
  posY.clear();
  posX.add(10);
  posY.add(10);
  appleX = (int)random(0,44);
  appleY = (int)random(0,44);
}
void key(){
   while (port.available() > 0){
    dato=port.readString();
    switch(dato){
      case "A":
        direccion=2;
      break;
      case "B":
        direccion=3;
      break;
      case "C":
        direccion=0;
      break;
      case "D":
        direccion=1;
      break;
      case "E":
        reset();
      break;
    }
   }
}
void choqueSnake(){ //para para cuando se choca con la serpiente
  for(int i=2; i<posX.size();i++){
    for(int j=2; j<posY.size();j++){
      if((posX.get(0)==posX.get(i))&&(posY.get(0)==posY.get(i))){ // recorre los dos bucles para tener la condicion de que se choca tiene que resetear
         gameOver=true;
      }
    }
  }
}
void bordes(){ //para ver los limites del juego
  if((posX.get(0)<0)|| (posX.get(0)>columnas-1) || (posY.get(0)<0) || (posY.get(0)>filas-1)){
    gameOver=true;
  }
}
