//codigo laboratorio 3

#include <stdio.h>
#include <wiringPi.h>
#include <iostream>
#include <math.h> //declarando as bibliotecas necessarias para este projeto

using namespace std;

 
#define  PINO  7     //definindo porta GPIO 7 com nome PINO 
#define ENVIA 0     //definindo porta GPIO 0 com nome ENVIA

 
int main (void)
{
float avg, sub,temp;    //variaveis auxiliares ao processo
float x,y,i,j;
cout<<"program to measure the temperature"<< endl ; //imprime nome do programa
 
      wiringPiSetup () ;
pinMode (PINO, INPUT) ; //define que PINO È uma entrada GPIO
pinMode(ENVIA,OUTPUT); //define que ENVIA È uma saida GPIO
pullUpDnControl (PINO,PUD_OFF); //define resistor interno nulo para o GPIO
for(;;) // mesmo codigo para calcular o PWM do laboratorio anterior, nesse caso estamos medindo o valor de tens„o adquirido do circuito de condicionamento de sinais
{
for (j=0;j<10;j++)
          {
x=0;
y=0; 
for(i=0;i<400;i++)
{
        if(digitalRead(PINO))
{
x=x+1;
}
                        else
{
y=y+1;
}
                        delayMicroseconds (10);
}
             sub= x/(x+y);
             avg = avg+sub;
         }
avg = 5*avg/10;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   avg = 5*avg/10;
        temp = (pow(0.729,avg))*53.52;    // converte o valor de tens„o para temperatura digital feito no experimento anterior
  
         cout<<"The temperature is "<< temp <<" C"<< endl;
 
         if (temp<=45)         // condicao para acender a lampada, considerando a temperatura atual como 25 C
{        
             digitalWrite(ENVIA,HIGH);    // comando para enviar o sinal para acender a lampada para o transmissor
                  cout<<"Envia Sinal para acender"<<endl;
          }

         else 
{
digitalWrite(ENVIA,LOW);    // comando para enviar o sinal para apagar a lampada para o transmissor
            cout<<"Envia sinal para manter pagar"<<endl;
            }
 
                                                 }
avg =0;
temp=0;  
     }
 
   return 0 ;
 }
