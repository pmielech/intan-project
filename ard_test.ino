#define therm1 A0
#define therm2 A1
#define volPin A2
#define volPelt A3

int cnt;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
  cnt = 0;
}

void loop() {
  Serial.print("Pomiar ");
  Serial.println(cnt);
  Serial.print("Therm1: ");
  thermRead(therm1);
  delay(500);
  Serial.print("Therm1: ");
  thermRead(therm2);
  cnt+=1;
  Serial.print("Peltier volt: ");
  voltRead(volPelt);
  Serial.print("Vout: ");
  voltRead(volPin);
  delay(500);

}

void thermRead(int therm) {
  
  Vo = analogRead(therm);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;
  if (therm == A0) {
    Serial.println(Tc-4);
  }
  else 
    Serial.println(Tc-2);
}

void voltRead(int pin) {
    float value;
    float volt;
    value = analogRead( pin );
    volt = value * 5.0 / 1023.0;
    Serial.println( volt );

}
