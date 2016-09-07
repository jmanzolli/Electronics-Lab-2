//Controle da lâmpada

#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 1 is BCM_GPIO 18.

#define PINO    1 

int main (void)
{
float alto,total, c1, c2, c3, c4, c5, c6;
float baixo,i,j,media,temp,aux1,aux2,aux3,aux4,aux5,aux6,aux7;
 
  printf ("Medida da temperatura\n") ;

  wiringPiSetup () ; //inicializaÁ„o
  pinMode (PINO, INPUT) ; //configura como entrada o sinal PWM que vem do conjunto LM324 + INA222
  pullUpDnControl (PINO,PUD_OFF); //desliga pull-up e pull down
   
  //variaveis auxiliares de referencia de temperatura baseado no calculo de Va e Vb no HW	
  aux1=5.391643117;
  aux2=4.963101604;
  aux3=4.376923077;
  aux4=3.602158273;
  aux5=2.620523303;
  aux6=1.414006515;
  aux7=0;

  //calculo do coeficiente angular, considerando que o intervalo entre dois pontos consecutivos È linear
  c1=(10-20)/(aux1-aux2);  
  c2=(20-30)/(aux2-aux3);
  c3=(30-40)/(aux3-aux4);
  c4=(40-50)/(aux4-aux5);
  c5=(50-60)/(aux5-aux6);
  c6=(70-60)/(aux6-aux7);

while(1){   //loop infinito de calculo da temperatura mesmo codigo do experimento passado

media = 0;

for(j=0;j<100;j++){ //faz 100 medidas da tens„o para calcular a media
alto = 0;
baixo = 0;

  for (i=0;i<400;i++){


        if (digitalRead(PINO)){
                alto = alto + 1;}

        else {
        baixo = baixo + 1;}
        
        delayMicroseconds (10) ;    
}  

total = alto/(alto+baixo);
media = media + total;	

}

media = 5*media/100;	//calcula valor da media da tensao

printf ("Tensao = %.2f V\n", med); //escreve na tela o valor da tensao medida

/* compara as medidas da tensoes com as referencias e calcula a temperatura*/

if (media>=aux2)
temp = 10 + c1*(media - aux1);

else if (media>=aux3)
temp = 20 + c2*(media - aux2);

else if (media>=aux4)
temp = 30 + c3*(media - aux3);

else if (media>=aux5)
temp = 40 + c4*(media - aux4);

else if (media>=aux6)
temp = 50 + c5*(media - aux5);

else
temp = 60 + c6*(media - aux6);


printf ("Temperatura = %.2f ∞C\n\n", T); //imprime o valor atual da temperatura 

}
  return 0 ;
}
