#define cwa 6
#define ccwa 7
#define cwb 4
#define ccwb 5
int x;
void robmove(int dir) {
  if (dir == 1) {
    digitalWrite(cwa, HIGH);  //turns forward
    digitalWrite(ccwa, LOW);
    digitalWrite(cwb, HIGH);
    digitalWrite(ccwb, LOW);
  }
  if (dir == 0) {
    digitalWrite(cwa, LOW);  //turns back
    digitalWrite(ccwa, HIGH);
    digitalWrite(cwb, LOW);
    digitalWrite(ccwb, HIGH);
  }
  if (dir == 2) {
    digitalWrite(cwa, HIGH);  //stops moving
    digitalWrite(ccwa, HIGH);
    digitalWrite(cwb, HIGH);
    digitalWrite(ccwb, HIGH);
  }
}
void robturn(int clck) {
  if (clck == 1) {  //turns right
    digitalWrite(cwa, HIGH);
    digitalWrite(ccwa, LOW);
    digitalWrite(cwb, LOW);
    digitalWrite(ccwb, HIGH);
  }
  if (clck == 0) {

    digitalWrite(cwa, LOW);  //turns left
    digitalWrite(ccwa, HIGH);
    digitalWrite(cwb, HIGH);
    digitalWrite(ccwb, LOW);
  }
  if (clck == 2) {
    digitalWrite(cwa, HIGH);  //stops moving
    digitalWrite(ccwa, HIGH);
    digitalWrite(cwb, HIGH);
    digitalWrite(ccwb, HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(cwa, OUTPUT);
  pinMode(ccwa, OUTPUT);
  pinMode(cwb, OUTPUT);
  pinMode(ccwb, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(3);
  Serial.println(x);
  delay(200);
  if (x <= 200) {
    Serial.println("white");
    robmove(0);
    delay(500);
    robturn(1);
    delay(1000);
  
  }
  if (x >= 300) {
    robmove(1);
    Serial.println("black");
    //delay(500);
  }
}
