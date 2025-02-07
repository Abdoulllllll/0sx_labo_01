const int ledPin = 13;  
int del=2048/256;
int delai=2000;
int delai_clignotement=250;
void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void allumerLED() {
    Serial.println("Allumé - 2412433");
    digitalWrite(ledPin, HIGH);
    delay(delai);
}

void clignoterLED(int nombreClignotements) {
    Serial.println("Clignotement - 2412433");

    int intensite = 50; 
    int incrementation = (255 - intensite) / nombreClignotements;

    for (int i = 0; i < nombreClignotements; i++) {
        analogWrite(ledPin, intensite);
        delay(delai_clignotement);
        analogWrite(ledPin, 0);
        delay(delai_clignotement);
        intensite += incrementation;
    }
}

void varierIntensiteLED() {
    Serial.println("Variation - 2412433");

    for (int i = 0; i <= 255; i++) {
        analogWrite(ledPin, i);
        delay(del);
    }
}

void eteindreLED() {
    Serial.println("Éteint - 2412433");
    digitalWrite(ledPin, LOW);
    delay(delai);
}

void loop() {
    allumerLED();
    clignoterLED(3);  
    varierIntensiteLED();
    eteindreLED();
}
