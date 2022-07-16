#define breset 12
#define bset 11

//Função para reiniciar o jogo.
int reset(){ 
  for (int led =2 ; led<11; led++){
    digitalWrite(led, LOW);
  }
 return 0;
 //Condição para o ciclo reset terminar.
}
//Função para o LED acender.
int set(){
  for(int led = 2 ; led < 11; led++){
    digitalWrite(led,HIGH);
  }
  return 0;
}
//Função para os leds que se encontram acesos piscarem, se não estiver aceso o ciclo termina
//se tiver aceso os leds acendem e apagam quando junatmos com a função abaixo.
int leds_acesos(){
 	int led_aceso = 1;
 	for ( int led = 2; led < 11 && led_aceso!= 0; led++){
    	if(digitalRead(led) == LOW){
    	  	led_aceso = 0; 
           //Se o led não estiver aceso termina o ciclo e permanece desligado.
    	}
  }
  return led_aceso; 
}

 //Função para permitir que os leds acendam e apaguem num intervalo de 20000ms.
int vitoria(int tempo, int tempo_espera){
  
  int inicio = millis();
  int atual = millis();
  while(atual - inicio <= tempo_espera){
    set();
    delay(tempo);
    reset();
    delay(tempo);
   	atual = millis();
  }
   
  return 0;  
//Termina o ciclo.
}

void setup() {

  Serial.begin(9600);
  
  pinMode(bset,INPUT_PULLUP);
  pinMode(breset,INPUT_PULLUP);
  
  for (int i = 2; i < 11; i++){
   	 pinMode(i, OUTPUT);
  }
}


void loop() {

	int tempo = 500;
	int tempo_espera=20000;
	int contador = 0;
   
	for (int led = 2 ; led < 11; led++){
	//Condição para que o contador comece de novo e o ciclo comece novamente no led 2.
  // Permite também que apenas os leds que se encontram acesos acendam.
	 if (leds_acesos() ){
         contador = vitoria(tempo,tempo_espera);
       	 led = 2; 
   // para voltar ao inicio do ciclo
     }

     if (digitalRead(bset)== 0){
       digitalWrite(led, HIGH);
       delay(tempo);
       contador++;
       Serial.println(contador);
      }
      
      
    if (digitalRead(led)==LOW){
        digitalWrite(led, HIGH);
        delay(tempo);
        digitalWrite(led, LOW);
        delay (tempo);   
      } 
      
    if (digitalRead(breset) == 0){
        contador = reset();
        //O contador começa de novo.
    }
  
  }
    //Trabalho realizado por: Inês Martins Marçal.
}
