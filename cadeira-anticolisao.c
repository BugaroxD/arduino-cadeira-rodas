#define pinTrig 3
#define pinEcho 4
#define time 10
int frequence = 0;
int PinBuzzer = 9;
float distance;
void leitura();

void setup()
{
    Serial.begin(9600);
    pinMode(pinTrig, OUTPUT);
    pinMode(pinEcho, INPUT);
    pinMode(PinBuzzer, OUTPUT);
    digitalWrite(pinTrig, LOW);
}
void loop()
{
    leitura();
    distance = distance / 2;
    distance = distance * 0.034029;
    Serial.print("distance em cm: ");
    Serial.println(distance);
    delay(100);
    if (distance < 50)
    {
        tone(PinBuzzer, 1000, 1000);
        delay(10);
        noTone(PinBuzzer);
        delay(10);
    }
    if (distance >= 50 and distance <= 100)
    {
        tone(PinBuzzer, 450, 1000);
        delay(25);
        noTone(PinBuzzer);
        delay(25);
    }
    if (distance >= 100 and distance <= 200)
    {
        tone(PinBuzzer, 500, 1050);
        delay(100);
        noTone(PinBuzzer);
        delay(100);
    }
    if (distance >= 200 and distance <= 250)
    {
        tone(PinBuzzer, 650, 1100);
        delay(200);
        noTone(PinBuzzer);
        delay(200);
    }
    if (distance >= 250 and distance <= 300)
    {
        tone(PinBuzzer, 650, 1150);
        delay(250);
        noTone(PinBuzzer);
        delay(250);
    }
}
void leitura()
{
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);
    distance = pulseIn(pinEcho, HIGH);
}