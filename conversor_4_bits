#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

#define A    0
#define B    1
#define C    2
#define D    5

void CONVERSOR(int entrada); //prototipo da funcao CONVERSOR

int main(void){

 wiringPiSetup () ;
 pinMode (A, OUTPUT) ;
 pinMode (B, OUTPUT) ;
 pinMode (C, OUTPUT) ;
 pinMode (D, OUTPUT) ;

int aux;
int i =0;
while(;;){

for ( i=0; i<16 ; i++){ 
    
    printf("Digite um valor decimal que será convertido para 4 bits:");
    scanf("%d",&aux);
    CONVERSOR(aux);
    
}
i=0;
}
return 0 ;


void CONVERSOR(int entrada) {            //funcao conversora de decimal para binario
    
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

    if (c==1){               
        digitalWrite (C,HIGH);
        }
    else {
        digitalWrite (C,LOW);
        }
    if (b==1){               
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
