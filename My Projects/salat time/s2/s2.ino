#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3or.h Salat time");
}

  double d,D,g,q,L,R,e,RA,EqT,jd,Dhu,Lng,TimeZone, Y, M, DD;
  double Fajr, Isha;
  
void loop() {
  // put your main code here, to run repeatedly:
  Y = 2021;
  M = 10;
  DD = 30;
   jd = 367 * Y - (7 * (Y + 5001 + (M - 9)/7))/4 + (275 * M)/9 + DD + 1729777;
   //jd = 2459517.595;
   
   d = jd - 2451545.0;  // jd is the given Julian date 

   g = 357.529 + 0.98560028* d;
   q = 280.459 + 0.98564736* d;
   L = q + 1.915* sin(g) + 0.020* sin(2*g);

   R = 1.00014 - 0.01671* cos(g) - 0.00014* cos(2*g);
   e = 23.439 - 0.00000036* d;
   RA = atan2(cos(e)* sin(L), cos(L))/ 15;

   D = asin(sin(e)* sin(L));  // declination of the Sun
   EqT = q/15 - RA;  // equation of time

   Lng = 31.953949;
   TimeZone = 2;
   Dhu = 12 + TimeZone - Lng/15 - EqT;
   
   Fajr = Dhu - T(18);
   Isha = Dhu + T(17);
   
   lcd.setCursor(0, 1);
   lcd.print(Fajr);
}

double T(double ang){
  return ((1/15)*(acos((-sin(ang)-sin(L)*sin(D))/(cos(L)*cos(D)))));
}
