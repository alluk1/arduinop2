#define LED 6
#define PAINIKE 5
#define LEDON HIGH
#define LEFOFF LOW
#define TASO1 180
#define TASO2 50
#define FILTER 20
int oldState;//Painikkeen tilojen seurantaa varten
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
    Serial.println("\\o/");
  }
}
