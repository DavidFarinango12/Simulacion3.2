/*
 * CAPITULO III:MODULOS DE COMUNICACION
 * CODIGO 10:USO DE VECTORES Y DATOS TIPO STRING
 * OBJETIVO:CODIFICADOR DE VOCALES DE 3 BITS
 * NOMBRE:RAFAEL FARINANGO
 * FUNCIONES DE PROGRAMACION:
 * Serial.begin(velocidad)->9600,19200,38400,57600
 * String stringOne = "Hello String";                     //constante como string
 * String stringOne = String('a');                        //convertir un dato de tipo char en string
 * String stringtwo = String("This is a string");         //convertir dos constantes en string
 * String stringOne = String(StringTwo + "With more");    //concatenar string
 * String stringone = (13);                               //convertir una constante int en string
 * String.length();                                       //tamaño del dato tipo string
 * dato.toCharArray(vector,tam)                           //convierte a cadena de tipo string
 */

//Codificacion: a=001;  e=010;  i=011;  o;100 u=101;
String dato;
String salida;
int tam;
int i=0;
int j=0;

 
void setup() {
  Serial.begin(9600);
}


void loop() {
  if(Serial.available()>0){
    dato=Serial.readString(); //revisa si existen datos a ser leidos
    dato.toLowerCase(); //convierte los datos ingresados en minusculas
    tam=dato.length()+1; //conocer el tamaño del dato
    //se crea un vector que separara a lasvocales ingresadas por comunicacion serial
    char vector [tam];
    dato.toCharArray(vector,tam);//almacena cada caracter en una posicion del vector
    //valida que todos los caracteres sean vocales
    for(i=0;i<tam-1;i++){
      if(vector[i]=='a' || vector[i]=='e' || vector[i]=='i' || vector[i]=='o' || vector[i]=='u')
        Serial.print(' ');
      else
        j++;//cuneta los errores de ingreso
      }
    Serial.println(j); //muestra cuantas letras no fueron vocales
    if(j>0)
      Serial.println("Error.!");
    else{
      Serial.println("Validado.!");
      for(i=0;i<tam-1;i++){
        switch (vector[i]){
          case 'a':
          salida=salida+"001"; //concatena mensaje
          break;
          case 'e':
          salida=salida+"010";
          break;
          case 'i':
          salida=salida+"011";
          break;
          case 'o':
          salida=salida+"100";
          break;
          case 'u':
          salida=salida+"101";
          break;
          }
        }
      }
    j=0; //reinicia el contador
    Serial.println(salida); //envia mensaje de vocales codificadas
    salida=""; //borra los datos almacenados
    
    }
}
