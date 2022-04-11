//Inicialização do Blynk
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID  "********"

//Bibliotecas
#include <ESP8266WiFi.h> //ESP8266
#include <BlynkSimpleEsp8266.h> //Blynk ESP8266
#include<HCSR04.h> //Sensor Ultrasônico

//Valriáveis
char auth[] = "******"; //Token para comunicação com o Blynk
char ssid[] = "*******"; //Nome da rede que deve se conectar
char pass[] = "********"; //Senha da rede que deve se conectar


//Definições
#define PIN_TRIGGER D5 //Pino D4 como Trigger para o Sensor Ultrasonico
#define PIN_ECHO D4 //Pino D5 como Echo para o Sensor Ultrasonico

//Inicializa o sensor nos pinos definidos acima
HCSR04 hc(PIN_TRIGGER,PIN_ECHO);

// Timer Blynk para leitura do sensor ultrasônico
BlynkTimer TimerSensorUltrasonico;
  void LerSensorUltrasonico(){
    int c = hc.dist(); //Função que faz o calculo em centimetros do ultrasônico dentro da biblioteca HCSR04
    Blynk.virtualWrite(V0, c);  //Pino Virtual 0 está definido no Blynk para coletar os dados do Ultrasônico
    Serial.println(c);
    delay(2000);
  }

/******** INICIANDO LEITURA DOS RELES *************/
//PINO NODEMCU D0
BLYNK_WRITE(V1){ //Parametro da biblioteca Blynk para iniciar o Pino Virtual 0 previamente configurado na paltaforma dentro do Template
  int ValorDoPino0 = param.asInt();//variável da biblioteca Blynk para a leitura dos botões
  if(ValorDoPino0 == 1){  //IF para caso o valor da variável ValorDoPino0 for igual a 1 deixa-lo em estado HIGH
    digitalWrite(D0, HIGH);
  } else {
    }
  if(ValorDoPino0 == 0){  //IF para caso o valor da variável ValorDoPino0 for igual a 0 deixa-lo em estado LOW
    digitalWrite(D0, LOW);
  } else {
    }
}

//PINO NODEMCU D1
BLYNK_WRITE(V2){  //Parametro da biblioteca Blynk para iniciar o Pino Virtual 2 previamente configurado na paltaforma dentro do Template
  int ValorDoPino1 = param.asInt(); //variável da biblioteca Blynk para a leitura dos botões
  if(ValorDoPino1 == 1){  //IF para caso o valor da variável ValorDoPino1 for igual a 1 deixa-lo em estado HIGH
    digitalWrite(D1, HIGH);
  } else {
    }
  if(ValorDoPino1 == 0){  //IF para caso o valor da variável ValorDoPino1 for igual a 0 deixa-lo em estado LOW
    digitalWrite(D1, LOW);
  } else {
    }
}

//PINO NODEMCU D2
BLYNK_WRITE(V3){  //Parametro da biblioteca Blynk para iniciar o Pino Virtual 3 previamente configurado na paltaforma dentro do Template
  int ValorDoPino2 = param.asInt(); //variável da biblioteca Blynk para a leitura dos botões
  if(ValorDoPino2 == 1){  //IF para caso o valor da variável ValorDoPino2 for igual a 1 deixa-lo em estado HIGH
    digitalWrite(D2, HIGH);
  } else {
    }
  if(ValorDoPino2 == 0){  //IF para caso o valor da variável ValorDoPino2 for igual a 0 deixa-lo em estado LOW
    digitalWrite(D2, LOW);
  } else {
    }
}

//PINO NODEMCU D3
BLYNK_WRITE(V4){  //Parametro da biblioteca Blynk para iniciar o Pino Virtual 4 previamente configurado na paltaforma dentro do Template
  int ValorDoPino3 = param.asInt(); //variável da biblioteca Blynk para a leitura dos botões
  if(ValorDoPino3 == 1){  //IF para caso o valor da variável ValorDoPino3 for igual a 1 deixa-lo em estado HIGH
    digitalWrite(D3, HIGH);
  } else {
    }
  if(ValorDoPino3 == 0){  //IF para caso o valor da variável ValorDoPino3 for igual a 0 deixa-lo em estado LOW
    digitalWrite(D3, LOW);
  } else {
    }
}

//PINO NODEMCU D6
BLYNK_WRITE(V5){  //Parametro da biblioteca Blynk para iniciar o Pino Virtual 5 previamente configurado na paltaforma dentro do Template
  int ValorDoPino6 = param.asInt(); //variável da biblioteca Blynk para a leitura dos botões
  if(ValorDoPino6 == 1){  //IF para caso o valor da variável ValorDoPino6 for igual a 1 deixa-lo em estado HIGH
    digitalWrite(D6, HIGH);
  } else {
    }
  if(ValorDoPino6 == 0){  //IF para caso o valor da variável ValorDoPino6 for igual a 0 deixa-lo em estado LOW
    digitalWrite(D6, LOW);
  } else {
    }
}

//PINO NODEMCU D7
BLYNK_WRITE(V6){  //Parametro da biblioteca Blynk para iniciar o Pino Virtual 6 previamente configurado na paltaforma dentro do Template 
  int ValorDoPino7 = param.asInt(); //variável da biblioteca Blynk para a leitura dos botões
  if(ValorDoPino7 == 1){  //IF para caso o valor da variável ValorDoPino7 for igual a 1 deixa-lo em estado HIGH
    digitalWrite(D7, HIGH);
  } else {
    }
  if(ValorDoPino7 == 0){  //IF para caso o valor da variável ValorDoPino7 for igual a 0 deixa-lo em estado LOW
    digitalWrite(D7, LOW);
  } else {
    }
}

void setup()
{
  //Definição dos Pinos como Saida de Dados
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  
  Serial.begin(9600); //Inicia o monitor Serial
  Blynk.begin(auth, ssid, pass);//Inicia o blynk utilizando as variáveis AUTH, SSID, PASS
  TimerSensorUltrasonico.setInterval(2000L, LerSensorUltrasonico);//Inicia o Timer com tempo de envio de 2000 milisegundos
  
}
void loop()
{
  Blynk.run();//Inicializa o Blynk;
  TimerSensorUltrasonico.run();//Inicializa o Timer 
}
