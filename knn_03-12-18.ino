//#include "dato_02.h"
#include "datos_03.h"
//#include "dat.h"
//float vector[4] ={6.4,2.7,5.3,1.9}; //
int on = 0;
float result ;
int  a = 0, b = 0, total = 0;



void setup() {
  Serial.begin(9600);

}
void loop(){
if (on == 0) {
    for (int i = 0; i <= 33; i++) {
      result = knn(33, 5, 3, 3, matriz[i]);
      if (result == matriz[i][4]) {
        a++;
      }
      else {
        b++;
      }
    }
    Serial.println("Aciertos: ");
    Serial.println(a);
    Serial.println("Erroneos: ");
    Serial.println(b);

    total = (a * 100) / 33;
    Serial.println("Eficiencia");
    Serial.println(total);

    on = 1;
  }
}

  

  float knn (int fila, int col,int k, int label,float datos[]){
  int c=0; // movernos en columnas 
  int f=0; // movernos en fila 
  float k_vecinos_dist[k]; // vector de almacenamiento de k distancias menores 
  float etiquetas [2][label]; // matriz y conteo de etiquetas
  float dist=0; // variable que almacena cada distancia
  float dist_total=0; // varaible para almacenamiento de distancia
  // llenar vector k_vecinos_dist con valores altos
  float eti_menor[k]; //vector de etiquetas de distancia menor
  int k_cont=0;
  int i=0; 
  float clase; // retornar etiqueta
  float comparacion; // comparar k-vecino mayor
   for(;c<k;c++){
    k_vecinos_dist[c]=2000.0+c;  // valores altos y ordenados
    }
    c=0; // reiniciar varaible
  // llenar matriz etiquetas
   for(;c<label;c++){
      etiquetas[0][c]=c+1;  // lleno con valores de etiqueta
      etiquetas[1][c]=0;  // lleno con el conteo de etiqueta
    }
    c=0; //renicio variable
    // la distacia mas corta del nuevo punto hacia la matriz

   for(;f<fila;f++){
      for(;c<col-1;c++){
        dist=dist+pow((matriz[f][c]-datos[c]),2); // distancia entre dos puntos
        }
        dist_total=sqrt(dist); // raiz de la formula
       // Serial.println(dist_total);
       for(;k_cont<k;k_cont++){ // determinar las k distancias menores y ordenarlas
           if(dist_total<k_vecinos_dist[k_cont]){
            k_vecinos_dist[k_cont]=dist_total; // asignar nuevo valor a vector de distancias menores
            eti_menor[k_cont]=matriz[f][col-1];  // col =5 , 4
            }
        }
       k_cont=0;
       dist=0;
       dist_total=0;
       c=0;            
     } //for fila

     // seleccion de los k vecino
    for(;c<label;c++){
      for(;k_cont<k;k_cont++){  // recorro cada posicion de eti_menor y comparo con etiquetas y cuento si son iguales
         if(etiquetas[0][c]==eti_menor[k_cont]){
            i++;
            etiquetas[1][c]=i;
          }
        }
        k_cont=0;
        i=0;
      }
      c=1; 
      comparacion = etiquetas[1][0];
      clase=etiquetas[0][0];
      for(;c<label;c++){
         if(etiquetas[1][c]>comparacion){ // comparacion entre valores de suma de etiqueta
          clase=etiquetas[0][c];
          comparacion=etiquetas[1][c];
          }
        }
        comparacion=0;
        c=0;
        return clase;   
  }
