// Lampu Pedestrian
const int ped1R = 13; 
const int ped1G = 12;

// Lampu Pedestrian
const int ped2R = 11; 
const int ped2G = 10;

// Lampu Kendaraan
const int vehR = 7; 
const int vehY = 6; 
const int vehG = 5;

// Pin Tombol Interupsi
const int buttonPin = 2;

// Variabel volatile
volatile bool adaPenyebrang = false;

void setup() {
  // Inisialisasi
  pinMode(vehR, OUTPUT); pinMode(vehY, OUTPUT); pinMode(vehG, OUTPUT);
  pinMode(ped1R, OUTPUT); pinMode(ped1G, OUTPUT);
  pinMode(ped2R, OUTPUT); pinMode(ped2G, OUTPUT);
  
  // Set pin input
  pinMode(buttonPin, INPUT_PULLUP);
 
  attachInterrupt(digitalPinToInterrupt(buttonPin), tombolDitekan, FALLING);
  
  // reset
  kondisiAwal();
}

void loop() {
  if (adaPenyebrang == true) {
    prosesPenyebrangan();
    adaPenyebrang = false;
  }
}

void tombolDitekan() {
  adaPenyebrang = true; 
}

void kondisiAwal() {
  digitalWrite(vehR, LOW); digitalWrite(vehY, LOW); digitalWrite(vehG, HIGH);
  
  digitalWrite(ped1G, LOW); digitalWrite(ped1R, HIGH);
  digitalWrite(ped2G, LOW); digitalWrite(ped2R, HIGH);
}

void prosesPenyebrangan() {
  digitalWrite(vehG, LOW);
  digitalWrite(vehR, HIGH);
  
  digitalWrite(ped1R, LOW); digitalWrite(ped1G, HIGH);
  digitalWrite(ped2R, LOW); digitalWrite(ped2G, HIGH);
  
  delay(5000);
  
  digitalWrite(ped1G, LOW); digitalWrite(ped1R, HIGH);
  digitalWrite(ped2G, LOW); digitalWrite(ped2R, HIGH);
  
  digitalWrite(vehR, LOW);
  digitalWrite(vehY, HIGH);
  
  delay(2000);
  
  digitalWrite(vehY, LOW);
  kondisiAwal();
}
