
/*
 *    UNIVERSIDAD TÉCNICA DEL NORTE
 *          FICA-CITEL
 *      SISTEMAS EMBEBIDOS
 * Nombre: Carlos Guerrón
 * Fecha: 19/01/2021
 * LABORATORIO 4 
 * OBJETIVO:Imprimir los puntos del conjunto de entrenamiento correspondientes a la regresión lineal (peso-estatura)
 * y la tendencia lineal o exponencial.
 * Al ingresar un nuevo valor por comunicacion serial al sistema electronico, realizar el pronostico (en
 * depedencia de la interfaz si se desea una tendencia lineal o exponencial) y graficarlo en la interfaz
 * con un color diferente a lo ya visto del conjunto de entrenamiento. 
 */
 #include <SoftwareSerial.h>   //llamamos a la libreria que nos ayuda a la cx serial por sofware
 SoftwareSerial sftSerial(2,3); //ponemos un nombre a la cx serial, usualmente se usa los pines (2,3) y (10,11)
 int matriz [14][2]{
 {170,67},
 {180,80},
 {170,65},
 {178,75},
 {160,55},
 {163,60},
 {165,63},
 {170,70},
 {164,62},
 {176,77},
 {164,60},
 {170,76},
 {170,56},
 {168,60}, 
  };
 int col=0;
 int fil=0;
 int Ex=0;  //sumatoria de x
 int Ey=0; //sumatoria de y
 long int Exy=0; //sumatoria de xy
 long int Ex2=0; //sumatoria de x^2
 long int Ex_2=0; //sumatoria de (Ex)^2
 int n=14; //tam de muestras
 float Bo; //Ordenada en el origen
 float m; //pendiente
 int m1;
 String dato;  //recibir estatura
 int estatura;  //convertir 
 int peso;
void setup() {
  Serial.begin(9600);
  sftSerial.begin(9600); //inciamos la cx serial por sofware
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);
  Bo=(float(Ex2*Ey)-float(Ex*Exy))/(float(n*Ex2-Ex_2));
  m1=(n*Exy)-(Ex*Ey);
  m=float(m1)/(float(n*Ex2-Ex_2));
  Serial.println("El modelo es: ");
  Serial.println(String("y= ")+String(m)+String("x")+String(Bo));
  Serial.println("Ingrese su estatura: ");
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=m*estatura+Bo;
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
    sftSerial.write(estatura);
    }
}
