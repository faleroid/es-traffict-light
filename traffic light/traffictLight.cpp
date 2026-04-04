// North Side
const int N_R = 13; const int N_Y = 12; const int N_G = 11;
// East Side
const int E_R = 10; const int E_Y = 9;  const int E_G = 8;
// South Side
const int S_R = 7;  const int S_Y = 6;  const int S_G = 5;
// West Side
const int W_R = 4;  const int W_Y = 3;  const int W_G = 2;

void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  
  allRed();
  delay(1000);
}

void loop() {  
  activateIntersection(N_R, N_Y, N_G); // North
  activateIntersection(E_R, E_Y, E_G); // East
  activateIntersection(S_R, S_Y, S_G); // South
  activateIntersection(W_R, W_Y, W_G); // West
}

void allRed() {
  // North
  digitalWrite(N_R, HIGH); digitalWrite(N_Y, LOW); digitalWrite(N_G, LOW);
  // East
  digitalWrite(E_R, HIGH); digitalWrite(E_Y, LOW); digitalWrite(E_G, LOW);
  // South
  digitalWrite(S_R, HIGH); digitalWrite(S_Y, LOW); digitalWrite(S_G, LOW);
  // West
  digitalWrite(W_R, HIGH); digitalWrite(W_Y, LOW); digitalWrite(W_G, LOW);
}

void activateIntersection(int pinRed, int pinYellow, int pinGreen) {
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  delay(5000);

  digitalWrite(pinGreen, LOW);

  for(int i = 0; i < 3; i++) {
    digitalWrite(pinYellow, HIGH);
    delay(300);
    digitalWrite(pinYellow, LOW);
    delay(300);
  }

  digitalWrite(pinYellow, HIGH);
  delay(2000);
  digitalWrite(pinYellow, LOW);

  digitalWrite(pinRed, HIGH);
}
