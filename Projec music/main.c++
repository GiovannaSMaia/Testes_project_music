/*O arquivo music está completo para colocar no main, ele está integrado com play-pause e tocador de músicas*/
#include <LiquidCrystal.h>


LiquidCrystal lcd(7,6,5,4,3,2);

#define BTN_UP 8
#define BTN_DOWN 9
#define BTN_PLAY 10
#define BTN_STOP 11
#define LED_PLAY 13
#define LED_STOP A1

int btnClicado = 0; //logica para deixar o led ligado quando apertarmos
int btnLiberado = 0;

int musicaAtual = 0;

char nomes[5][16] = {
  "Mario",
  "Zelda",
  "Tetris",
  "Pokemon",
  "StarWars"
};


void setup() {
  lcd.begin(16,2);

  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(BTN_PLAY, INPUT);
  pinMode(BTN_STOP, INPUT);
  pinMode(LED_PLAY, OUTPUT);
  pinMode(LED_STOP, OUTPUT);
  telaInicial();
  mostrarMenu();
}

void telaInicial() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bem vindo ao");
  lcd.setCursor(0,1);
  lcd.print("Music Fei");
  delay(2000);
}


void mostrarMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Selecione:");

  lcd.setCursor(0,1);
  lcd.print(nomes[musicaAtual]);
}

void tocar_musica(){
  
  if(digitalRead(BTN_PLAY)== HIGH){
  	digitalWrite(LED_PLAY, HIGH);
     delay(500);
    digitalWrite(LED_STOP, LOW);
  }
 
  if(digitalRead(BTN_STOP)==HIGH){
  	digitalWrite(LED_STOP, HIGH);
    delay(500);
   digitalWrite(LED_PLAY, LOW);
  }
    
}


void lerMenu() {

  // PROXIMA
  if(digitalRead(BTN_UP) == HIGH) {
    musicaAtual++;
    if(musicaAtual > 4) musicaAtual = 0;
    mostrarMenu();
    delay(200);
  }

  // ANTERIOR
  if(digitalRead(BTN_DOWN) == HIGH) {
    musicaAtual--;
    if(musicaAtual < 0) musicaAtual = 4;
    mostrarMenu();
    delay(200);
  }

  // PLAY (aqui você implementa depois)
  if(digitalRead(BTN_PLAY) == HIGH) {
    lcd.clear();
    lcd.setCursor(0,0);
    btnClicado = 1;
    lcd.print("Tocando:");
    lcd.setCursor(0,1);
    lcd.print(nomes[musicaAtual]);
    tocar_musica();

    delay(1000); // placeholder
   // mostrarMenu();
  }
}

void loop() {
  lerMenu();
  tocar_musica();
}



//esboço 
/*
void musica() {

  int melodia[] = {262, 294, 330, 349};
  int duracao[] = {150, 150, 150, 300};

  int tamanho = 4;
/*
  for(int i = 0; i < tamanho; i++) {
    //tone(BUZZER, melodia[i]);
    delay(duracao[i]);
    noTone(BUZZER);
    delay(50);
  }
  }
*/
