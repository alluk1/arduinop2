#define LED 6
#define PAINIKE 5
#define LEDON 255
#define LEDOFF 0
#define TASO1 150
#define TASO2 60
#define FILTER 20
int oldState;//Painikkeen tilojen seurantaa varten
int valaistusTaso = LEDOFF;
void setup(){
  pinMode(LED, OUTPUT);
  pinMode(PAINIKE, INPUT_PULLUP);
  oldState = digitalRead(PAINIKE);//Alustetaan "muistijälki"
  Serial.begin(9600);
}

bool buttonPressed(){
  bool retVal = false;
  int x = digitalRead(PAINIKE);
  if(x == LOW && oldState == HIGH){//Etsitään painikkeen painallus
    retVal = true;
  }
  oldState = x;
  delay(FILTER);
  return retVal;
}

void loop(){
  if(buttonPressed()){
    switch(valaistusTaso){
      case LEDOFF:valaistusTaso=LEDON;break;
      case LEDON:valaistusTaso=TASO1;break;
      case TASO1:valaistusTaso=TASO2;break;
      case TASO2:valaistusTaso=LEDOFF;break;
  }
  analogWrite(LED, valaistusTaso);
  }
}
