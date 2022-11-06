#define Vermelho_1 15
#define Verde_2 12
#define Amarelo_3 11
#define Branco_4 9
#define buzzer 18
#define Botao_1 16
#define Botao_2 7
#define ldr 14


// criando 5 sons 
int Buzzer[4] = {0, 0, 0, 0}; 
int ind = 0; 

// verificação  com 6 números 
int Binario[9] = { 1,2,3,4,5,6,7,8,9};

// Criação de uma função para salvar e converter valores
void SalvandoeConvertendo(int value){ 

  int colocabinario[4] = {0, 0, 0, 0}; 

  for (int i = 3; value != 0; i--){ 
    colocabinario[i] = value % 2; 
    value = value / 2; // valor convertido.
  }
    if (colocabinario[0] == 1){
      digitalWrite(Vermelho_1, HIGH); 
      delay(200);
    }

    if (colocabinario[1] == 1){
      digitalWrite(Verde_2, HIGH); // Controlando as saídas
    }

    if (colocabinario[2] ==1){
      digitalWrite(Amarelo_3, HIGH);
    }

    if (colocabinario[3] == 1){
      digitalWrite(Branco_4, HIGH); 
    }
    tone(buzzer, Buzzer[ind/4]); 
    delay(200);
    tone(buzzer, 0); //  buzzer parar
    digitalWrite(Vermelho_1, LOW);
    digitalWrite(Verde_2, LOW); 
    digitalWrite(Amarelo_3, LOW); 
    digitalWrite(Branco_4, LOW);

  int medir = (sizeof(Binario))/4; 
  Binario[ind] = colocabinario[0]; 
  Binario[ind+1] = colocabinario[1]; 
  Binario[ind+2] = colocabinario[2]; 
  Binario[ind+3] = colocabinario[3]; 

  if (ind!= medir) {
    ind+= 4;
  }

}
// Convertendo 
int convert(int n) {
  return n/ 273; // Conversão 
}

void setup() {
  Serial.begin(9600);
  pinMode(Vermelho_1, OUTPUT);
  pinMode(Verde_2, OUTPUT);
  pinMode(Amarelo_3, OUTPUT);
  pinMode(Branco_4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Botao_1, INPUT);
  pinMode(Botao_2, INPUT);
 // Usando o pinModo para controlar o resultado
}


void loop() {
  int Botao_1Valor = digitalRead(Botao_1); // lendo uma entrada digital do botão 1
  int Botao_2Valor = digitalRead(Botao_2); // lendo uma entrada digital do botão 2
  if (Botao_2Valor == 1) { // valor exato e tranforma
    delay(500); // delay de tempopara ativação
    ind= 0;
    for (int i = 0; i < 16; i = i+4) {
      if (Binario[i] == 1) {
        digitalWrite(Vermelho_1, HIGH);
      }
      if (Binario[i+1] == 1) {
        digitalWrite(Verde_2, HIGH);
      }
      if (Binario[i+2] == 1) {
        digitalWrite(Amarelo_3, HIGH);
      }
      if (Binario[i+3] == 1) {
        digitalWrite(Branco_4, HIGH);
      }
      tone(buzzer, Buzzer[i/4]); //buzzer na ordem.
      delay(500);
      digitalWrite(Vermelho_1, LOW);
      digitalWrite(Verde_2, LOW);
      digitalWrite(Amarelo_3, LOW);
      digitalWrite(Branco_4, LOW);
      tone(buzzer, 0);
      delay(200); // delay de tempopara ativação
    }
    Serial.print("\n");
    for (int ind= 0; ind< sizeof(Binario)/4; ind++) {
      Binario[ind] = 0;
    }
    for (int ind= 0; ind< sizeof(Buzzer); ind++) {
      Buzzer[ind] = 0;
    }
    Serial.println("Valores Zerados");
    Serial.println("Sons Zerados");
  }
  if (Botao_1Valor == 1) {
    delay(500); // delay de tempopara ativação
    int ldrValor = analogRead(Vermelho_1);
    ldrValor = convert(ldrValor);
    Serial.println(ind);
    
    Buzzer[ind/4] = ldrValor * 150;
    Serial.println(ldrValor);

    SalvandoeConvertendo(ldrValor);
  for (int element : Binario) {
    Serial.print(element);
    Serial.print(" ");
  }
  Serial.print("\n");
}
}