//TRANSMISSOR
//Importação das bibliotecas a serem utilizadas
#include <Arduino.h> 
#include<XBee.h>
//Realizarem comunicação serial com o módulo Xbee
#include<SoftwareSerial.h> 

//  --- Mapeamento das portas logicas
//Incicializa um construtor da biblioteca SoftwareSerial
//Cria um objeto XBEE1, passando as portas 3 e 4 para comunicação serial
SoftwareSerial XBEE1(3,4);

//Declaração de variáveis para leitura do Joystick
const int eixoX = A0;
const int eixoY = A1;
const int stop = 2;

//Declaração da variável passando a função XBee
XBee xbee = XBee();

// --- Inicialização ---
void setup() {
  
  Serial.begin(9600);
  //Iniciamos a porta XBEE1 responsável por enviar as informações
  //para o módulo Xbee e definimos o taxa de transmissão(baudrate) de 9600
  XBEE1.begin(9600);
  xbee.begin(Serial);  
  Serial.println("Iniciando........");
  pinMode (stop, INPUT_PULLUP); //inicializa o pino stop como uma entrada 
                                //com o resistor pull-up interno habilitado
                                // monitorando o estado do Joystick 
}

void loop() {
  //permitem usar as portas analógica do arduino como input
  int x = analogRead(eixoX); 
  int y = analogRead(eixoY);
  //Lê o valor do pino digital stop, pode ser HIGH/LOW 
  int posStop = digitalRead(stop);
  
  //Estrutura condicional
  if (x == 0) { //Se eixoX do Joystick for 0 
    XBEE1.print(1);
    //Serial.println("1");
  } else if (x == 1023) {
    XBEE1.print(2);
    //Serial.println("2");
  }else if (y == 0) {
    XBEE1.print(3);
    //Serial.println("3");
  } else if (y == 1023) {
    XBEE1.print(4);
    //Serial.println("4");
  }else if (digitalRead(posStop) == HIGH) {
    XBEE1.print(0); //para manter a comunicação constante
    //Serial.println("0");
  }  
  delay(50);
}
