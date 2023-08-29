const int trigPin = 4;
const int echoPin = 3;
const int buzzerPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak berdasarkan waktu tempuh gelombang
  float distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 5) {  // Jarak kurang dari 5 cm
    tone(buzzerPin, 1000); // Aktifkan buzzer dengan frekuensi 1000 Hz
  } else {
    noTone(buzzerPin); // Matikan buzzer
  }

  delay(100); // Jeda antara pengukuran
}
