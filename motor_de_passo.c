//Motor de Passo

#include <stdio.h>
#include <wiringPi.h>
// LED Pin - wiringPi pin 1 is BCM_GPIO 18.
#define L1	1
// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
#define L2	0
// LED Pin - wiringPi pin 2 is BCM_GPIO 27.
#define L3	2
// LED Pin - wiringPi pin 5 is BCM_GPIO 24.
#define L4	5

int main (void) {

int dir, step, interv, j, rest; 
wiringPiSetup () ; //inicialização
pinMode (L1, OUTPUT) ; //configura como saida para acionamento do motor
pullUpDnControl (L1, PUD_OFF);
pinMode (L2, OUTPUT) ; //configura como saida para acionamento do motor
pullUpDnControl (L2, PUD_OFF);
pinMode (L3, OUTPUT) ; //configura como saida para acionamento do motor
pullUpDnControl (L3, PUD_OFF);
pinMode (L4, OUTPUT) ; //configura como saida para acionamento do motor	
pullUpDnControl (L4, PUD_OFF);

while(1){ 

//loop infinito do programa
//menu de escolha para o usuario

printf ("Motor de Passos\n") ; printf ("Escolha a direção de rotação (0 = horario e 1 = anti-horario:\n");
scanf("%d", &dir);
printf ("Escolha o intervalo (ms) entre os passos:\n");
scanf("%d", &interv);
printf ("Escolha o número de passos (1 passo = 90º):\n");
scanf("%d", &step);

for(j=0;j<step;j++){ //loop do numero de passos do motor
	
	//Calculo do resto que indica qual sequencia corresponde ao passo atual
	rest = (j+1) % 4;
	
if (rest==0){ //o resto da divisao do quarto passo é zero, entao soma 4 para ficar na ordem
	rest = rest+4;
	}

  if ( dir == 0){ //sentido horario 		
              		if(rest==1){//passo 1
              		
              		digitalWrite(L1, LOW); // coloca tensao no led
              		
              		digitalWrite(L2, HIGH); // seta o led no GND
              		
              		digitalWrite(L3, LOW); // coloca tensao no led
              		
              		digitalWrite(L4, HIGH); // seta o led no GND
              		
              		delay (interv); //intervalo do passo
              		
              		}
              		
              		if(rest==2){//passo 2
              		
              		digitalWrite(L1, HIGH); //seta o led no GND
              		
              		digitalWrite(L2, LOW); // coloca tensao no led
              		
              		digitalWrite(L3, LOW); // coloca tensao no led
              		
              		digitalWrite(L4, HIGH); // seta o led no GND
              		
              		delay(interv); //intervalo do passo
              		
              		}
    if(rest==3){//passo 3
    
    digitalWrite(L1, HIGH); // seta o led no GND
    
    digitalWrite(L2, LOW); // coloca tensao no led
    
    digitalWrite(L3, HIGH); // seta o led no GND
    
    digitalWrite(L4, LOW); // coloca tensao no led
    
    delay(interv); //intervalo do passo
}

if(rest==4){//passo 4

digitalWrite(L1, LOW); // coloca tensao no led

digitalWrite(L2, HIGH); // seta o led no GND

digitalWrite(L3, HIGH); // seta o led no GND

digitalWrite(L4, LOW); // coloca tensao no led

delay(interv); //intervalo do passo

}	
}

if ( dir == 1){ //sentido anti-horario

if(rest==1){//passo 1

digitalWrite(L1, LOW); // coloca tensao no led

digitalWrite(L2, HIGH); // seta o led no GND

digitalWrite(L3, HIGH); // seta o led no GND

digitalWrite(L4, LOW); // coloca tensao no led

delay(interv); //intervalo do passo

}
  if(rest==2){//passo 2
  
  digitalWrite(L1, HIGH); // seta o led no GND
  
  digitalWrite(L2, LOW); // coloca tensao no led
  
  digitalWrite(L3, HIGH); // seta o led no GND
  
  digitalWrite(L4, LOW); // coloca tensao no led
  
  delay(interv); //intervalo do passo
  
  }
  if(rest==3){//passo 3
  
  digitalWrite(L1, HIGH); // seta o led no GND
  
  digitalWrite(L2, LOW); // coloca tensao no led
  
  digitalWrite(L3, LOW); // coloca tensao no led
  
  digitalWrite(L4, HIGH); // seta o led no GND
  
  delay(interv); //intervalo do passo
  
  }	
if(rest==4){//passo 4

digitalWrite(L1, LOW); // coloca tensao no led

digitalWrite(L2, HIGH); // seta o led no GND

digitalWrite(L3, LOW); // coloca tensao no led

digitalWrite(L4, HIGH); // seta o led no GND

delay(interv); //intervalo do passo
}
}
}

//desliga os led’s (motor)
digitalWrite(L1, HIGH);
digitalWrite(L2, HIGH);
digitalWrite(L3, HIGH);
digitalWrite(L4, HIGH);
}// end while

 return 0 ;
}
