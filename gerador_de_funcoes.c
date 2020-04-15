#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

#define A    0
#define B    1
#define C    2
#define D    5
#define PI 3.141516

void CONVERSOR(int entrada); //prototipo da funcao CONVERSOR

int main( ){

 wiringPiSetup () ;
 pinMode (A, OUTPUT) ;
 pinMode (B, OUTPUT) ;
 pinMode (C, OUTPUT) ;
 pinMode (D, OUTPUT) ;

int i=0,j,passo,c,freq;
float x;
char k, myAux;
int y = 1;

while(y){                           /*obtem o tipo de onda*/
printf ("Aperte 1 para onda senoidal e 2 para onda triangular\n");
scanf("%d",&k);

switch (k){
    case 1: 
     k=1;
     y = 0; 
    break;
    case 2:
        k=2;
        y=0;
     break;
    default: printf("Digite um valor v·lido (1 ou 2)\n");
}        
}

while (i != 0){                /*obtem o valor da frequencia*/
printf ("Digite a frequencia de 500 a 5000 Hz\n");
scanf ("%d",&freq);
if( freq >= 500 || freq <= 5000){
    i = 1;   
    }
}

/*onda senoidal*/
if (k==1){

passo = 1000000/(32*freq);                 /*calcula a distancia entre valores baseado na frequencia*/

while (1){
c=0;
for (x=(-1*PI);x <= PI ;x=(x+PI/16)){            /*faz uma onda de -pi atÈ pi em passos de pi/16 */

j = 8 + 7*sin(x);                    /*calcula um valor aproximado para a saida de acordo com uma senoide*/

CONVERSOR(j);                 //escreve o valor calculado na saida
delayMicroseconds(passo);       //aguarda o tempo de um passo
}
}
}

/*onda triangular*/
if (k==2){
passo = 1000000/(30*freq);          //calcula o intervalo entre os valores

j=0;
while (1){

while (j<15){                 	//rampa de subida
CONVERSOR(j); 		//escreve o valor calculado na saida
j = j+1;
delayMicroseconds(passo);//aguarda o valor do passo
    }

while (j>0){                 	//rampa de descida
CONVERSOR(j);                 //escreve o valor calculado na saida
j = j-1;
delayMicroseconds(passo);       //aguarda o valor do passo


        }
    }
}
return 0 ;
}

void CONVERSOR(int entrada) {            //funcao que converte uma entrada decimal inteira em um array de 4 bits.
    
    int a,b,c,d;

    d = entrada%2;
    entrada = entrada/2;
    c = entrada%2;
    entrada = entrada/2;
    b = entrada%2;
    entrada = entrada/2;
    a = entrada%2;
    
    if (d==1){                //bit menos significativo
        digitalWrite (D,HIGH);
            }
    else {
        digitalWrite (D,LOW);
        }

    if (c==1){                //segundo bit menos significativo
        digitalWrite (C,HIGH);
        }
    else {
        digitalWrite (C,LOW);
        }
    if (b==1){                //segundo bit mais significativo
        digitalWrite (B,HIGH);
        }
    else {
        digitalWrite (B,LOW);
        }
    if (a==1){                //bit mais significativo
        digitalWrite (A,HIGH);
        }
    else {
        digitalWrite (A,LOW);
        }
}
