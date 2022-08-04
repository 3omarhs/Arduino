#include <String.h>
#include <PrayerTimes.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <Rtc_Pcf8563.h>
Rtc_Pcf8563 rtc;


// seting date to 19 Jul 2020
//String yearr = "20" + (String)rtc.getYear();
//int my_year = ((String)"20"+(String)rtc.getYear()).toInt(); //2021;
/*int my_year = 2021;
int my_month = /*rtc.getMonth(); /* //10;
/*int my_day = /*rtc.getDay(); /*/ //31;
int my_year;
int my_month;
int my_day;
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
  
void timee(){
  my_year = 2021;
  my_month = rtc.getMonth();
  my_day = rtc.getDay();
}

void setup() {
  Serial.begin(9600);
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3or.h Salat time");

  timee();
  
  Serial.print("*******  Prayer Times for the date : ");
  Serial.print(my_month);  Serial.print("/");Serial.print(my_day);  Serial.print("/");Serial.print(my_year);  Serial.print(" *******\n\n");
  set_to_sunnyvale();
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
    
    /*lcd.setCursor(0, 1);
    lcd.print(my_prayer_object.get_prayer_name(i));
    lcd.print(inStringForm);*/
  }
/*
  Serial.println("\n");

  
  set_to_mumbai();
  Serial.println("===================== Mumbai , India =====================");
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
*/

}

void loop() {
  // put your main code here, to run repeatedly:
//  or_read();

  String now_time = (String)rtc.getHour() + ":" + (String)rtc.getMinute();
  String plus_two_time = now_time;
  
  
//  Serial.println(plus_two_time);
  for (int i = 0; i < my_prayer_object.TimesCount; ++i) {
    if((i != 1)&&(i != 4)){
      inStringForm = my_prayer_object.float_time_to_time24 (my_prayer_times[i]);
      if((i != 1)&&(i != 4)){
          int now_t1 = plus_two_time.substring(0, 2).toInt();
          int now_t2 = plus_two_time.substring(3, -1).toInt();
          if(now_t2 == 1){   //////////////////////////////////////////////////////////////////////////for 2 min before
            now_t1 = now_t1 - 1;
            now_t2 = 59;
          }
          else if(now_t2 == 0){   //////////////////////////////////////////////////////////////////////////for 2 min before
            now_t1 = now_t1 - 1;
            now_t2 = 58;
          }
          else{
            now_t2 = now_t2 - 2;
          }
            plus_two_time = now_t1;
            plus_two_time += ":";
            plus_two_time += now_t2;
//            if(plus_two_time == "12:54"){
            if(inStringForm == plus_two_time){
              SalahtTime(my_prayer_object.get_prayer_name(i));
            }
//        if(inStringForm == now_time){
//          Serial.println("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
//          lcd.setCursor(0, 1);
//          lcd.print("-*-*-*-*-*-*-*-");
//        }
      }
    }
  }
}

void SalahtTime(String salaht){
  lcd.setCursor(0, 1);
  lcd.print(salaht);
  lcd.print(" time now...");
  Serial.println(salaht);
}

// Sunnyvale , CA, USA specific value
void set_to_sunnyvale() {
    my_latitude = 31.898417; //31.9;    //31.898417, 35.890132
    my_longitude = 35.890132; //35.9;
    my_timezone = 2;
    my_dst_on = false;     // True between March to September
    my_calc_method = "Karachi";
    my_asr_method = "Shafii";
    my_high_lats_method = "None";
}


void or_read(){
  set_to_sunnyvale();
  my_prayer_object.get_prayer_times(my_year, my_month, my_day, my_latitude , my_longitude , my_timezone , my_dst_on, my_calc_method, my_asr_method, my_high_lats_method, my_prayer_times );
  for (int i = 0; i < my_prayer_object.TimesCount; ++i) {
    if((i != 1)&&(i != 4)){
      inStringForm = my_prayer_object.float_time_to_time24 (my_prayer_times[i]);
      inStringForm = my_prayer_object.float_time_to_time12 (my_prayer_times[i]);
      
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(my_prayer_object.get_prayer_name(i));
      lcd.print(inStringForm);
      delay(2000);
    }
}
}

// Mumbai , MH , India specific value
/*
void set_to_mumbai () {
  my_latitude = 19.097403;
  my_longitude = 72.874245;
  my_timezone = 5.5;
  my_dst_on = false;    // Never used in India
  my_calc_method = "Karachi";
  my_asr_method = "Shafii";
  my_high_lats_method = "None";
}*/
