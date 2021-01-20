/*
 *    UNIVERSIDAD TÉCNICA DEL NORTE
 *          FICA-CITEL
 *      SISTEMAS EMBEBIDOS
 * Nombre: Carlos Guerrón
 * Fecha: 19/01/2021
 * LABORATORIO 4 
 * OBJETIVO:Imprimir los puntos del conjunto de entrenamiento correspondientes a la regresión lineal (peso-estatura)
 * y la tendencia lineal o exponencial.
 * Al ingresar un nuevo valor por comunicación serial al sistema electrónico, realizar el pronostico (en
 * depedencia de la interfaz si se desea una tendencia lineal o exponencial) y graficarlo en la interfaz
 * con un color diferente a lo ya visto del conjunto de entrenamiento. 
 */
 import processing.serial.*; //libreria para la cx serial
 Serial port; //nobramos el puerto serial
 float peso; // datos del peso
 float estatura;  //datos de estatura
 float estatura_aux=0; // auxiliar para los datos de la estatura
 int aux=0; //auxiliar 
 
 void setup(){
   
   port= new Serial(this, "COM10",9600); // llamamos a la cx serial con el puerto 10
   size(950,650); // anchoy alto de la ventana
   background(#D0D1AF); // color de fondo 
   //lineas de la parte exterior 
   stroke(0);
   strokeWeight(1.5);
   line(150,135,150,580);
   line(150,580,750,580);
   line(150,580,750,580);
   //lineas de la parte interior de la grafica
   stroke(#595A35);
   strokeWeight(0.5);
   line(150,135,750,135);
   line(300,135,300,580);
   line(450,135,450,580);
   line(600,135,600,580);
   line(750,135,750,580);
   line(150,530,750,530);
   line(150,480,750,480);
   line(150,430,750,430);
   line(150,380,750,380);
   line(150,330,750,330);
   line(150,280,750,280);
   line(150,230,750,230);
   line(150,180,750,180);
   //textos que van en la interfaz
   //numeros de la grafica
   textSize(15);
   fill(#0005F5);
   //alturas
   text("0",125,590);
   text("10",115,530);
   text("20",115,480);
   text("30",115,430);
   text("40",115,380);
   text("50",115,330);
   text("60",115,280);
   text("70",115,230);
   text("80",115,180);
   text("Peso (Kg)",120,125);
   //pesos
   textSize(15);
   fill(#F51E0A);
   text("150",140,600);
   text("160",290,600);
   text("170",440,600);
   text("180",590,600);
   text("190",740,600);
   text("Altura (cm)",790,590);
   stroke(#A4A5A3);
   strokeWeight(0.5);
   line(340,0,340,90);
   line(740,0,740,90);
   line(340,90,740,90);
   line(0,95,950,95);
   //presentacion
   textSize(25);
   fill(#0005F5);
   text("Laboratorio 4 - Carlos Guerrón",350,30);
   text("Regresión Lineal",450,80);
   textSize(15);
   fill(#F51E0A);
   text("y=1.1797x-133.39",780,400);
   text("R2=0.7036",780,420);
 }
void serialEvent(Serial port){
  estatura=port.read(); //lee el valor de estatura de la cx serial
  estatura_aux=int(estatura); //convierte a int el dato
  println("Estatura ingresada: ");  //imprimimos la estatura que se ingreso
  println(estatura);  
  peso=estatura*(1.1797)-133.39;  //realizamos la ecuacion para encontrar el peso
  println("El peso es: ");  //imprimimos el peso
  println(peso);
}
void draw(){
  if(peso>0){  //condicion para dibujar la estatura ingresada
    stroke(#078B1C);
    strokeWeight(1);
    fill(#078B1C);
    ellipse((estatura*15)-2100,580-(peso)*5,10,10); //dibujar el nuevo punto 
  }
  stroke(#F0181F);
  strokeWeight(1);
  line(150*15-2100,580-43.565*5,(190*15)-2100,580-90.753*5); //linea de la regresion
  stroke(#11078B);
  strokeWeight(2);
  fill(#11078B);
  //puntos de la matriz 
  ellipse((170*15)-2100,580-67*5,5,5);  
  ellipse((180*15)-2100,580-80*5,5,5); 
  ellipse((170*15)-2100,580-65*5,5,5); 
  ellipse((178*15)-2100,580-75*5,5,5); 
  ellipse((160*15)-2100,580-55*5,5,5); 
  ellipse((163*15)-2100,580-60*5,5,5); 
  ellipse((165*15)-2100,580-63*5,5,5); 
  ellipse((170*15)-2100,580-70*5,5,5); 
  ellipse((164*15)-2100,580-62*5,5,5); 
  ellipse((176*15)-2100,580-77*5,5,5); 
  ellipse((164*15)-2100,580-60*5,5,5); 
  ellipse((170*15)-2100,580-76*5,5,5); 
  ellipse((170*15)-2100,580-56*5,5,5); 
  ellipse((168*15)-2100,580-60*5,5,5); 

}
 
 
