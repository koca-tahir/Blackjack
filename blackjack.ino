#define a 8
#define b 7
#define c 6
#define d 5
#define e 4
#define f 3
#define g 2
#define yLed 13
#define kLed 12
#define kButon 11
#define mButon 10

int kasaSonuc = 0;
int oyuncuSonuc = 0;
bool oyunBasladi = false;

void setup() {
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(kLed, OUTPUT);
  pinMode(kButon, INPUT);
  pinMode(mButon, INPUT);
  
  randomSeed(analogRead(A0)); 
}

void loop() {
  int mavi = digitalRead(mButon);
  int kirmizi = digitalRead(kButon);
  
  // --- MAVİ BUTON: KART ALMA ---
  if (mavi == 1) {
    if (!oyunBasladi) {
      // Oyun ilk defa başlıyorsa kasanın skorunu belirle
      kasaSonuc = random(16, 22);
      oyuncuSonuc = random(1, 11); // İlk kart
      oyunBasladi = true;
      Serial.println("--- OYUN BASLADI ---");
    } else {
      // Oyun zaten başladıysa yeni kart ekle
      oyuncuSonuc += random(1, 11);
    }
    
    Serial.print("Senin Skorun: ");
    Serial.println(oyuncuSonuc);
    
    // 21'i geçtiysen otomatik kaybetme kontrolü
    if (oyuncuSonuc > 21) {
      Serial.println("21'i gectin! Kaybettin.");
      digitalWrite(kLed, HIGH); // Hata durumunu belirtmek için kLed
      delay(1000);
      digitalWrite(kLed, LOW);
      
      // Oyunu sıfırla
      oyuncuSonuc = 0;
      kasaSonuc = 0;
      oyunBasladi = false;
    }
    
    delay(300); // Buton arkını (bounce) önlemek için kısa bekleme
  }
  
  // --- KIRMIZI BUTON: DUR / SKORLARI KARŞILAŞTIR ---
  if (kirmizi == 1 && oyunBasladi) {
    Serial.println("--- KART CEKMEYI DURDURDUN ---");
    Serial.print("Kasanin Skoru: ");
    Serial.println(kasaSonuc);
    Serial.print("Senin Skorun: ");
    Serial.println(oyuncuSonuc);
    
    if (oyuncuSonuc > kasaSonuc) {
      Serial.println("Tebrikler, Kazandin!");
      digitalWrite(yLed, HIGH);
      delay(1000);
      digitalWrite(yLed, LOW);
    } 
    else if (oyuncuSonuc < kasaSonuc) {
      Serial.println("Kasa kazandi, Kaybettin.");
      digitalWrite(kLed, HIGH);
      delay(1000);
      digitalWrite(kLed, LOW);
    } 
    else {
      Serial.println("Berabere!");
    }
    
    // Oyunu sıfırla
    oyuncuSonuc = 0;
    kasaSonuc = 0;
    oyunBasladi = false;
    
    delay(300); // Buton arkını önlemek için
  }
}

// 7 Segment fonksiyonlarına dokunulmadı, senin entegrasyonunu bekliyorlar
void bir() {
  digitalWrite(d, 0); digitalWrite(g, 1); digitalWrite(a, 1);
  digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(e, 0);
  digitalWrite(f, 1);
}
void iki(){
  digitalWrite(a, 0); digitalWrite(b, 1); digitalWrite(c, 0);
  digitalWrite(d, 0); digitalWrite(e, 1); digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void uc(){
  digitalWrite(a, 0); digitalWrite(b, 1); digitalWrite(c, 0);
  digitalWrite(d, 0); digitalWrite(e, 0); digitalWrite(f, 0);
  digitalWrite(g, 1);
}
void dort(){
  digitalWrite(a, 0); digitalWrite(b, 0); digitalWrite(c, 1);
  digitalWrite(d, 0); digitalWrite(e, 0); digitalWrite(f, 1);
  digitalWrite(g, 1);
}
void bes(){
  digitalWrite(a, 0); digitalWrite(b, 0); digitalWrite(c, 0);
  digitalWrite(d, 1); digitalWrite(e, 0); digitalWrite(f, 0);
  digitalWrite(g, 1);
}
void alti(){
  digitalWrite(a, 0); digitalWrite(b, 0); digitalWrite(c, 0);
  digitalWrite(d, 1); digitalWrite(e, 0); digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void yedi(){
  digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 0);
  digitalWrite(d, 0); digitalWrite(e, 0); digitalWrite(f, 1);
  digitalWrite(g, 1);
}
void sekiz(){
  digitalWrite(a, 0); digitalWrite(b, 0); digitalWrite(c, 0);
  digitalWrite(d, 0); digitalWrite(e, 0); digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void dokuz(){
  digitalWrite(a, 0); digitalWrite(b, 0); digitalWrite(c, 0);
  digitalWrite(d, 0); digitalWrite(e, 0); digitalWrite(f, 0);
  digitalWrite(g, 1);
}
