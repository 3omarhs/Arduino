#include <String.h>
#include <PrayerTimes.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <Rtc_Pcf8563.h>
Rtc_Pcf8563 rtc;
int relay = 5;
unsigned long azan_time;
unsigned long my_time;

//edited library from: "C:\Users\Omar Hassan\Documents\Arduino\libraries\PrayerTimes\PrayerTimes.h" (line 105)>>      method_params[Makkah]  = MethodConfig(18.0, true,  0.0, true,  90.0); // Makkah   //**19.0 not 18.5 edited by 3omar.hs

//http://praytimes.org/wiki/Calculation_Methods


//what to edit:

// not karatchi.. >> my_calc_method = "Karachi";//mecha/egypt;    //done..
//my_dst_on = false;     // True between March to September    inside if statement.   //done



////////edit on: may/7/2022 >>          Sunrise -6, Asr +1, Maghrib +6, Isha +1 ...
////////edit on: may/10/2022>>          Sunrise -5, Asr +1, Maghrib +5
////////edit on: may/11/2022>> Fajr -1, Sunrise -6, Asr +1, Maghrib +6, Isha +1
////////edit on: may/12/2022>> Fajr -1, Sunrise -7, Asr +1, Maghrib +7, Isha +1




int my_year;
int my_month;
int my_day;
int my_hour;
int my_minute;
double my_latitude;
double my_longitude;
double my_timezone;
bool my_dst_on;
String my_calc_method;
String my_asr_method;
String my_high_lats_method;

// Please refer to http://praytimes.org/manual for details of all above parameters.
PrayerTimes my_prayer_object;   // PrayerTimes object
double my_prayer_times[my_prayer_object.TimesCount];  // Array for receiveing prayer times

String inStringForm;

void timee() {
  String yy = "20" + (String)rtc.getYear();
  my_year = yy.toInt();
  my_month = rtc.getMonth();
  my_day = rtc.getDay();
  my_hour = rtc.getHour();
  my_minute = rtc.getMinute();
  lcd.setCursor(8, 0);
  lcd.print(my_day);
  lcd.setCursor(10, 0);
  lcd.print("_");
  lcd.print(my_hour);
  lcd.print(":");
  lcd.print(my_minute);
}

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  //  digitalWrite(relay, HIGH);
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3.h ST. ");

  my_time = millis();

  timee();

  Serial.print("*******  Prayer Times for the date : ");
  Serial.print(my_month);  Serial.print("/"); Serial.print(my_day);  Serial.print("/"); Serial.print(my_year);  Serial.print(" *******\n\n");
  set_to_sunnyvale();
  String s_w = "Winter";
  if ((my_month > 2) && (my_month < 11))
    s_w = "Summer";
  Serial.print(s_w);
  Serial.println(" time..");
  Serial.println("===================  Sunnyvale, Amman, Jordan  =================");   //CA, USA
  Serial.println("Prayer\t\tNumberic-Time\t24Hr-Format\t12Hr-Format");
  Serial.println("----------------------------------------------------------");
  my_prayer_object.get_prayer_times(my_year, my_month, my_day, my_latitude , my_longitude , my_timezone , my_dst_on, my_calc_method, my_asr_method, my_high_lats_method, my_prayer_times );
  for (int i = 0; i < my_prayer_object.TimesCount; ++i) {
    Serial.print(my_prayer_object.get_prayer_name(i)); Serial.print("\t\t");
    Serial.print(my_prayer_times[i]); Serial.print("\t\t");
    inStringForm = my_prayer_object.float_time_to_time24 (my_prayer_times[i]);
    Serial.print(inStringForm); ; Serial.print("\t\t");
    inStringForm = my_prayer_object.float_time_to_time12 (my_prayer_times[i]);
    Serial.println(inStringForm);
  }
}

void loop() {
  or_read();
  salaht_reminder();
  timee();
  if (millis() >= azan_time + 240000) { //240000    //60000    //180000
    digitalWrite(relay, LOW);
  }
  Serial.println();
  Serial.print("Time: ");
  String ttn = (String)rtc.getHour();
  ttn += ":";
  ttn += (String)rtc.getMinute();
  Serial.print(ttn);
  Serial.print(":");
  Serial.println(rtc.getSecond());
  Serial.print("time with sub 2 min: ");
  Serial.println(subtract_two_minutes(ttn));

  //    my_time = millis();
}

void SalahtTime(String salaht) {
  lcd.setCursor(0, 1);
  lcd.print(salaht);
  lcd.println(" time now...");
  digitalWrite(relay, HIGH);
  azan_time = millis();
  delay(10000);
}

// Sunnyvale , Amman, Jordan specific value
//https://www.islamicfinder.org
//https://www.islamicfinder.org/world/hashemite-kingdom-of-jordan/250441/amman-prayer-times/
//https://prayertimes.date/amman
void set_to_sunnyvale() {
  my_latitude = 31.95; //31.963158;//31.898417; //31.9;    //31.898417;      //**31.8360368;     //****31.8986802;
  my_longitude = 35.9333; //35.930359;//35.890132; //35.9;    //35.890132;      //**36.2278245;     //****35.89079;
  if ((my_month > 2) && (my_month < 11))
    my_timezone = 3;
  else
  my_timezone = 2;
  
//  for summer time (timezone you can use my_dst_on instead of manual set)

//  if ((my_month >= 3) && (my_month < 9))
//    my_dst_on = true;
//  else
//    my_dst_on = false;     // True between March to September
    
  my_calc_method = "Makkah";//Makkah(Umm Al_Qura)/Egypt/(Karachi 90%)/MWL/ISNA/Jafari;
  my_asr_method = "Shafii"; //"Hanafi, (Shafii 100%)";
  my_high_lats_method = "None"; //MidNight, OneSeventh, AngleBased, None
}

void or_read() {
  set_to_sunnyvale();
  my_prayer_object.get_prayer_times(my_year, my_month, my_day, my_latitude , my_longitude , my_timezone , my_dst_on, my_calc_method, my_asr_method, my_high_lats_method, my_prayer_times );
  for (int i = 0; i < my_prayer_object.TimesCount; ++i) {
    if ((i != 1) && (i != 4)) {
      inStringForm = my_prayer_object.float_time_to_time24 (my_prayer_times[i]);
      inStringForm = my_prayer_object.float_time_to_time12 (my_prayer_times[i]);

      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(my_prayer_object.get_prayer_name(i));
      lcd.print(" ");
      lcd.print(inStringForm);
      delay(2000);
    }
    timee();
    salaht_reminder();
    Serial.println();
  }
}

void salaht_reminder() {
  String now_time = (String)my_hour + ":" + (String)my_minute;

  for (int i = 0; i < my_prayer_object.TimesCount; ++i) {
    if ((i != 1) && (i != 4) && (i != 5)) {
      inStringForm = my_prayer_object.float_time_to_time24 (my_prayer_times[i]);
      if (inStringForm == subtract_two_minutes(now_time)) {
        SalahtTime(my_prayer_object.get_prayer_name(i));
        Serial.print(my_prayer_object.get_prayer_name(i)); Serial.print("\t");
        Serial.print(now_time);
        Serial.println("is active now..");
      }
      Serial.print("now time: ");
      Serial.print(now_time);
      Serial.print("\t"); Serial.print("\t");
      Serial.print(my_prayer_object.get_prayer_name(i));
      Serial.print(" time:");
      Serial.println(inStringForm);
    }
    else if (i == 5) {
      inStringForm = my_prayer_object.float_time_to_time24 (my_prayer_times[i]);
      if (inStringForm == add_five_minutes(subtract_two_minutes(now_time))) {
        SalahtTime(my_prayer_object.get_prayer_name(i));
        Serial.print(my_prayer_object.get_prayer_name(i)); Serial.print("\t");
        Serial.print(now_time);
        Serial.println("is active now..");
      }
      Serial.print("now time: ");
      Serial.print(now_time);
      Serial.print("\t"); Serial.print("\t");
      Serial.print(my_prayer_object.get_prayer_name(i));
      Serial.print(" time:");
      Serial.println(inStringForm);
    }
  }
}

String add_five_minutes(String input_time) {
  int now_t1 = input_time.substring(0, 2).toInt();
  int now_t2 = input_time.substring(3, input_time.length()).toInt();

  int mg_t1 = input_time.substring(0, 2).toInt();
  int mg_t2 = input_time.substring(3, input_time.length()).toInt();

  /*if (now_t2 == 55) {
    mg_t1 = mg_t1 + 1;
    mg_t2 = 00;
    }
    else if (mg_t2 == 56) {
    mg_t1 = mg_t1 + 1;
    mg_t2 = 1;
    }
    else if (mg_t2 == 57) {
    mg_t1 = mg_t1 + 1;
    mg_t2 = 2;
    }
    else if (mg_t2 == 58) {
    mg_t1 = mg_t1 + 1;
    mg_t2 = 3;
    }
    else if (mg_t2 == 59) {
    mg_t1 = mg_t1 + 1;
    mg_t2 = 4;
    }
    else {
    mg_t1 = now_t1;
    mg_t2 = now_t2 + 5;
    }
    input_time = mg_t1;
    input_time += ":";
    input_time += mg_t2;*/


  if (now_t2 == 00) {
    mg_t1 = mg_t1 - 1;
    mg_t2 = 55;
  }
  else if (mg_t2 == 1) {
    mg_t1 = mg_t1 - 1;
    mg_t2 = 56;
  }
  else if (mg_t2 == 2) {
    mg_t1 = mg_t1 - 1;
    mg_t2 = 57;
  }
  else if (mg_t2 == 3) {
    mg_t1 = mg_t1 - 1;
    mg_t2 = 58;
  }
  else if (mg_t2 == 4) {
    mg_t1 = mg_t1 - 1;
    mg_t2 = 59;
  }
  else {
    mg_t1 = now_t1;
    mg_t2 = now_t2 - 5;
  }
  input_time = mg_t1;
  input_time += ":";
  input_time += mg_t2;

  return input_time;
}

String subtract_two_minutes(String input_time) {
  //One minute only//
  int now_t1 = input_time.substring(0, 2).toInt();
  int now_t2 = input_time.substring(3, input_time.length()).toInt();
  /*if (now_t2 == 1) { //////////////////////////////////////////////////////////////////////////for 2 min before
    now_t1 = now_t1 - 1;
    now_t2 = 59;
    }
    else if (now_t2 == 0) { //////////////////////////////////////////////////////////////////////////for 2 min before
    now_t1 = now_t1 - 1;
    now_t2 = 58;
    }
    else {
    now_t2 = now_t2 - 2;
    }*/

  /*if (now_t2 == 58) { ///////////////////////
    now_t1 = now_t1 + 1;
    now_t2 = 00;
    }*/
  if (now_t2 == 59) {
    now_t1 = now_t1 + 1;
    now_t2 = 0;
  }
  else {
    now_t2 = now_t2 + 1;
  }//////////////////////////////////////////////
  input_time = now_t1;
  input_time += ":";
  input_time += now_t2;
  return input_time;
}
