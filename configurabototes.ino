/***********************************************************************
Essa parte do código configura o controle remoto, entre as funçoes estão:
-> Funcao que recebe o codigo do modulo RF
-> Função que grava os botoes
-> Funcao que identifica os botoes gravados
-> Funcao que guarda os botões gravados na memória.
***********************************************************************/

/***********************************************************************
                      DECLARAÇÃO DAS VARIÁVEIS
***********************************************************************/
void verificabotaoacionado();


/***********************************************************************
                  VERIFICA QUAL BOTÃO FOI ACIONADO
***********************************************************************/
void verificabotaoacionado()
{
  if (mySwitch.available()) {
    value = mySwitch.getReceivedValue();
    Serial.print("value É:");
    Serial.println(value);
    mySwitch.resetAvailable();
    if(value == 2444872)
    {
        bot_acionado=1;
    }
    if(value == 2444868)
    {
        bot_acionado=2;
    }
    if(value == 2444876)
    {
        bot_acionado=3;
    }
    if(value == 2444866)
    {
        bot_acionado=4;
    }
    if(value == 2444874)
    {
        bot_acionado=5;
    }
    if(value == 2444870)
    {
        bot_acionado=6;
    }
    if(value == 2444871)
    {
        bot_acionado=7;
    }
    if(value == 2444879)
    {
        bot_acionado=8;
    }
  }
    if(bot_acionado == 1 )
  {
    Serial.println("BOTAO 1 ACIONADOOO");
    ledcWrite(0, 0);
  }
    if(bot_acionado == 2 )
  {
    Serial.println("BOTAO 2 ACIONADOOO");
    ledcWrite(0, 100);
  }
    if(bot_acionado == 3 )
  {
    Serial.println("BOTAO 3 ACIONADOOO");
    ledcWrite(0, 250);
  }
    if(bot_acionado == 4 )
  {
    Serial.println("BOTAO 4 ACIONADOOO");
    ledcWrite(0, 400);
  }
    if(bot_acionado == 5 )
  {
    Serial.println("BOTAO 5 ACIONADOOO");
    ledcWrite(0, 550);
  }
    if(bot_acionado == 6 )
  {
    Serial.println("BOTAO 6 ACIONADOOO");
    ledcWrite(0, 700);
  }
    if(bot_acionado == 7 )
  {
    Serial.println("BOTAO 7 ACIONADOOO");
    ledcWrite(0, 850);
  }
    if(bot_acionado == 8 )
  {
    Serial.println("BOTAO 8 ACIONADOOO");
    ledcWrite(0, 1000);
  }
}







