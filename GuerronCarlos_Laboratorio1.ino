 /*
 *     LABORATORIO 1
 * Nombre: Carlos Guerrón
 * Fecha: 24/11/2020
 * 
 */
 #include <Keypad.h>     // importa libreria Keypad
 #include <LiquidCrystal.h>  // importa la libreria para el LCD

LiquidCrystal lcd(A0,A1,A2,12,11,10); // pines a los que esta conceatdo el lcd RS,E,D4,D5,D6,D7
const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','C'},
  {'7','8','9','J'},
  {'*','0','#','G'}
};
//String txtbienvenido = "BIENVENIDO CARLOS GUERRON" ;
byte pinesFilas[FILAS] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columnas
int i;
const int btn=13;

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char TECLA;       // almacena la tecla presionada
char CLAVE[9];        // almacena en un array 8 digitos ingresados
const char CLAVE_1[9] = "CA900813";   // almacena en un array la contraseña 1
const char CLAVE_2[9] = "AJ881112";   // almacena en un array la contraseña 2 
const char CLAVE_3[9] = "JA890109";   // almacena en un array la contraseña 3
const char CLAVE_4[9] = "CG971115";   // almacena en un array la contraseña 4
String usuario1 = "Carlos Arias";  //asignamos variable a los mensajes que vamos a usar 
String usuario2 = "Andres Juarez";  //asignamos variable a los mensajes que vamos a usar 
String usuario3 = "Javier Andrada";  //asignamos variable a los mensajes que vamos a usar 
String usuario4 = "Carlos Guerron";  //asignamos variable a los mensajes que vamos a usar 
String dato;
String salida;
int tam;
byte INDICE = 0;      // indice del array
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);  // inicializamos el tamaño de nuestro lcd
  Serial.begin(9600);  //velocidad de nuetra comunicacion serial. 
  Serial.println("Universidad Tecnica del Norte");
  Serial.println("Carlos Guerron - Laboratorio 1");
  Serial.println("Ingrese la contrasena: ");
  //Serial.println("Presione # para imprimir el reporte: ");
  pinMode(btn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (TECLA)        // comprueba que se haya presionado una tecla
  {
    CLAVE[INDICE] = TECLA;    // almacena en array la tecla presionada
    INDICE++;       // incrementa indice en uno
    Serial.print(TECLA);    // envia a monitor serial la tecla presionada
    if(INDICE == 8)       // si ya se almacenaron los 8 digitos
  {
        if(!strcmp(CLAVE,CLAVE_1)||!strcmp(CLAVE,CLAVE_2)||!strcmp(CLAVE,CLAVE_3)||!strcmp(CLAVE,CLAVE_4)){   // compara clave ingresada con las claves de los usuarios
          // validacion clave 1
          if(!strcmp(CLAVE,CLAVE_1)){  
            Serial.println(" Clave Correcta");  // imprime en monitor serial que es correcta la clave
            Serial.println(" ");  // Imprime un espacio en blanco
            Serial.println("BIENVENIDO "+usuario1);  //imrpime el mensaje que deseamos 
            lcd.clear();      //limpia el lcd
            lcd.setCursor(0,0);   //coloca las palabras en la posicion inicial
            lcd.print("BIENVENIDO "+usuario1);   //imrpime el mesnaje en el lcd
            for(int j=0; j<29; j++){   //arreglo para que el texto aparzca en rotacion de datos
            lcd.scrollDisplayLeft();   // comando para hacer la rotacion de datos a la izquierda
            delay(300);
          }
            lcd.clear();
          }
          // validacion clave 2
          if(!strcmp(CLAVE,CLAVE_2)){
            Serial.println(" Clave Correcta"); 
            Serial.println(" ");
            Serial.println("BIENVENIDO "+usuario2); 
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("BIENVENIDO "+usuario2);
            for(int j=0; j<29; j++){
            lcd.scrollDisplayLeft();
            delay(300);
          }
            lcd.clear();
          }
          // validacion clave 3
          if(!strcmp(CLAVE,CLAVE_3)){
            Serial.println(" Clave Correcta"); 
            Serial.println(" ");
            Serial.println("BIENVENIDO "+usuario3); 
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("BIENVENIDO "+usuario3);
            for(int j=0; j<29; j++){
            lcd.scrollDisplayLeft();
            delay(300);
          }
            lcd.clear();
          }
          // validacion clave 4
           if(!strcmp(CLAVE,CLAVE_4)){
            Serial.println(" Clave Correcta"); 
            Serial.println(" ");
            Serial.println("BIENVENIDO "+usuario4); 
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("BIENVENIDO "+usuario4);
            for(int j=0; j<29; j++){
            lcd.scrollDisplayLeft();
            delay(300);
          }
            lcd.clear();
          }
       }
         else{
          Serial.println("Clave Incorrecta");  
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Clave Incorrecta");
          delay(300);
      }     
    INDICE=0;
  }
}
      if(digitalRead(btn) == HIGH){
          registro();
        }
}
void registro(){
       if(!strcmp(CLAVE,CLAVE_1)||!strcmp(CLAVE,CLAVE_2)||!strcmp(CLAVE,CLAVE_3)||!strcmp(CLAVE,CLAVE_4)){
  if(!strcmp(CLAVE,CLAVE_1)){
            Serial.println(" ");
            Serial.println(" Usuarios Registrados: "); 
            Serial.println(usuario1);     
            Serial.println(" Usuarios No Registrados: ");
            Serial.println(usuario2); 
            Serial.println(usuario3); 
            Serial.println(usuario4); 
            }
 if(!strcmp(CLAVE,CLAVE_2)){
            Serial.println(" ");
            Serial.println(" Usuarios Registrados: "); 
            Serial.println(usuario2);     
            Serial.println(" Usuarios No Registrados: ");
            Serial.println(usuario1); 
            Serial.println(usuario3); 
            Serial.println(usuario4); 
            }
  if(!strcmp(CLAVE,CLAVE_3)){
            Serial.println(" ");
            Serial.println(" Usuarios Registrados: "); 
            Serial.println(usuario3);     
            Serial.println(" Usuarios No Registrados: ");
            Serial.println(usuario1); 
            Serial.println(usuario2); 
            Serial.println(usuario4); 
            }
  if(!strcmp(CLAVE,CLAVE_4)){
            Serial.println(" ");
            Serial.println(" Usuarios Registrados: "); 
            Serial.println(usuario4);     
            Serial.println(" Usuarios No Registrados: ");
            Serial.println(usuario1); 
            Serial.println(usuario2); 
            Serial.println(usuario3); 
            }

       }
  
  }
