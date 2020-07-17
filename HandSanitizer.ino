#define trigPin 7
#define echoPin 8
#define led2 2
#define valvePin1 3
#define valvePin2 4

float duration, cm;
int counter = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(led2, OUTPUT);
  pinMode(valvePin1, OUTPUT);
  pinMode(valvePin2, OUTPUT);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2)/29.1;

  Serial.println(cm);

  if(cm <= 7){
      digitalWrite(led2, HIGH);
      digitalWrite(valvePin2, HIGH);
      digitalWrite(valvePin1, LOW);
      Serial.println("OPEN");
      delay(750);
      digitalWrite(valvePin2, LOW);
      digitalWrite(valvePin1, LOW);
      digitalWrite(led2, LOW);
      Serial.println("CLOSED");
      Serial.println("TAKE OUT YOUR HAND");
      delay(2000);
      Serial.println("DONE");
      }
  else{
    digitalWrite(valvePin2, LOW);
    digitalWrite(valvePin1, LOW);
  }
  digitalWrite(LED_BUILTIN, HIGH);   
  
}
