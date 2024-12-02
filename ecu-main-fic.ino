/***********************************************************************
                              BIBLIOTECAS
***********************************************************************/
#include <RCSwitch.h>
#include <EEPROM.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



/***********************************************************************
                              DEFINES
***********************************************************************/
#define loadpin 2
#define rfpin 17
#define buttonPin 18
#define sdadisplay 21
#define sckdisplay 22


/***********************************************************************
                        DECLARAÇÃO DE VARIÁVEIS
***********************************************************************/
/***********************************************************************
                                PWM
***********************************************************************/
//const int numpwms=4;                                                  /define o número de saidas pwm.
const int pwmFrequency = 5000;                                        //Frequencia do PWM
const int pwmResolution = 8;                                          //Resolução do PWM de 8 bits -> de 0 a 255
extern void funcao1escolhida();
extern void funcao2escolhida();
extern void funcao3escolhida();
extern void funcao4escolhida();
extern void funcao5escolhida();
extern void funcao6escolhida();
extern void funcao7escolhida();
extern void funcao8escolhida();



/***********************************************************************
                                RF
***********************************************************************/
const int receiverPin = 17;         // Pino D27 do ESP32 conectado ao modulo RF
const int numbotoes = 8;            // Armazena o número de botões que o controle tem
unsigned long value;                //variavel utilizada para receber os codigos que vem do controle remoto
bool isProgrammingMode = false;     //variavel usada para indicar se o código está em modo de programação do controle
int i=0;                            //variável auxiliar
unsigned long buttonCodes[numbotoes];// Armazena os códigos dos 8 botões
int currentButton = 0;              // Índice do botão atual
bool isPrefixEqual;                 //variavel usada para indicar se os códigos recebidos vem do mesmo controle
unsigned long firstPrefix;          //armazena o primeiro prefixo, que será usado para comparar com os próximos
unsigned long prefix;               //armazena o identificador do controle
byte lastDigits[numbotoes];         //vetor que armazena o código de cada digito
int bot_acionado;                   //variável que armazena o número do botão que está acionado
RCSwitch mySwitch = RCSwitch();     //Declarando o objeto RF
//Funcoes globais que sao usadas
extern void verificabotaoacionado();
extern void gravabotoes();
extern void identificabotoes();


/***********************************************************************
                              DISPLAY
***********************************************************************/
/***********************************************************************
                              DISPLAY
***********************************************************************/
//DECLARAÇÃO DAS VARIÁVEIS
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
//Essas variaveis tipo booleanas são usadas para identificar em qual tela o codigo está.
bool estanatelasenha=false;
bool estanatelaopcoes=false; 
bool telaconfigurapwm=false;
bool telaajusteintpwm=false; 
//outras variaveis
int telaopcao=1;
int canal=1;
int intensidade=0;
int canalescolhido=0;
unsigned long tempoinicio;
//funcoes globais que sao usadas
/****** Telas usadas*******/
extern void apresentacaodisplay();
extern void telainicial();
extern void logomarelli();



/***********************************************************************
                                FUNÇÃO SETUP
***********************************************************************/
void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.display();
  delay(2000);
  mySwitch.enableReceive(receiverPin);                                // Habilita o receptor RF no pino 27
  pinMode(5, OUTPUT);
  ledcSetup(0, 1000, 10);
  ledcAttachPin(5, 0);
  tempoinicio=millis();
}


/***********************************************************************
                                FUNÇÃO LOOP
***********************************************************************/
void loop() {
  verificabotaoacionado();                                    //essa função faz com que o código fique o tempo todo verificando se algum botão foi acionado
  apresentacaodisplay();
}






