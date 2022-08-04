#include <time.h>
#include <math.h>
#include <string.h>
using namespace std;

double dhuhr_minutes;
const int NUM_ITERATIONS = 1;   // number of iterations needed to compute times
double julian_date;
double latitude;  
double longitude;   
double Time_Zone;

static const char* TimeName[] = {"Fajr","Sunrise","Dhuhr","Asr","Sunset","Maghrib","Isha"};

enum JuristicMethod {Shafi, Hanafi};
enum TimeID{Fajr, Sunrise, Dhuhr, Asr, Sunset, Maghrib, Isha, TimesCount};

enum CalculationMethod{
  MWL,      // Muslim World League (MWL)
  Karachi,  // University of Islamic Sciences, Karachi
  ISNA,     // Islamic Society of North America (ISNA)
  Makkah,   // Umm al-Qura, Makkah
  Egypt,    // Egyptian General Authority of Survey
  Jafari,   // Jafari
  Tehran,   // Tehran
  CalculationMethodsCount
};
enum AdjustingMethod{     // Adjusting Methods for Higher Latitudes
  None,       // No adjustment
  MidNight,   // middle of night
  OneSeventh, // 1/7th of night
  AngleBased, // angle/60th of night
};
struct MethodConfig{
  double fajr_angle;
  bool   maghrib_is_minutes;
  double maghrib_value;   // angle or minutes
  bool   isha_is_minutes;
  double isha_value;    // angle or minutes

 MethodConfig(){
    fajr_angle = 18.0;
    maghrib_is_minutes = true;
    maghrib_value = 0.0;    // angle or minutes
    isha_is_minutes = false;
    isha_value = 18.0;    // angle or minutes
  }

 MethodConfig(double fajr_angle,
        bool maghrib_is_minutes,
        double maghrib_value,
        bool isha_is_minutes,
        double isha_value)
    : fajr_angle(fajr_angle)
    , maghrib_is_minutes(maghrib_is_minutes)
    , maghrib_value(maghrib_value)
    , isha_is_minutes(isha_is_minutes)
    , isha_value(isha_value)
    {
    }
};
  
MethodConfig method_params[CalculationMethodsCount];
unsigned int calc_method ;
unsigned int asr_juristic;
AdjustingMethod adjust_high_lats;


String two_digits_format(int num);
static String int_to_string(int num);
static double fix_hour(double a);
static void get_float_time_parts(double time, int& hours, int& minutes);
String float_time_to_time24(double Time);
String float_time_to_time12(double Time, bool no_suffix = false);
double deg2rad(double d);
double rad2deg(double r);
static double dsin(double d);
static double dcos(double d);
static double dtan(double d);
static double darcsin(double x);
static double darccos(double x);
static double darctan(double x);
static double darctan2(double y, double x);
static double darccot(double x);
static double fix_angle(double a);
static double time_diff(double time1, double time2);
void sun_position(double jd, double &D, double &Eq_t);
double equation_of_time(double jd);
double sun_declination(double jd);
double compute_mid_day(double _t);
double compute_time(double g, double t);
void day_portion(double times[]);
double compute_asr(int Step, double t);
void compute_times(double times[]);
double night_portion(double angle);
void adjust_high_lat_times(double times[]);
void adjust_times(double times[]);
void compute_day_times(double times[]);
double get_julian_date(int Year, int Month, int Day);  
void get_prayer_times(int Year, int Month, int Day, double _latitude, double _longitude, double _timezo, double times[]);
void get_prayer_times(time_t date, double latitude, double longitude, double Tzone, double times[]);
void setup (){
  Serial.begin(9600);
  adjust_high_lats = None;
  dhuhr_minutes = 0;
  Time_Zone  = 5;   // +5.0 for Pakistan  
  latitude  = 33.6633;   // for Islamabad
  longitude = 72.9915;    
  
}

void loop()
{
  char ch;
  do
  {

    Serial.println("---------------------------------------------------");
    Serial.println("Select Calculation Method for Fajr and Isha Prayers");
    Serial.println("*--------------------------------------------------");
    Serial.println("0 = Muslim World League                            ");
    Serial.println("1 = University of Islamic Sciences, Karachi        ");
    Serial.println("2 = Islamic Society of North America (ISNA)        ");
    Serial.println("3 = Umm al-Qura University, Makkah                 ");
    Serial.println("4 = Egyptian General Authority of Survey           ");
    Serial.println("5 = Shia Ithna Ashari, Leva Research Institute     ");
    Serial.println("6 = Institute of Geophysics, University of Tehran  ");
    Serial.println("---------------------------------------------------");
    do{
    }while(Serial.available() < 1);
    ch = Serial.read();
    if( ch < '0' || ch > '6' )
      Serial.println("Invalid Input Option");
    
  }while(ch < '0' || ch > '6' );
  
  calc_method = ch & 0x0F;
  method_params[0] = MethodConfig(18.0, true,  0.0, false, 17.0); // MWL
  method_params[1] = MethodConfig(18.0, true,  0.0, false, 18.0); // Karachi
  method_params[2] = MethodConfig(15.0, true,  0.0, false, 15.0); // ISNA
  method_params[3] = MethodConfig(18.5, true,  0.0, true,  90.0); // Makkah
  method_params[4] = MethodConfig(19.5, true,  0.0, false, 17.5); // Egypt
  method_params[5] = MethodConfig(16.0, false, 4.0, false, 14.0); // Jafari
  method_params[6] = MethodConfig(17.7, false, 0.0, false, 14.0); // Tehran


  
  
  do
  {
    
    Serial.println("");
    Serial.println("Select Juristic Method for Asr Prayer");
    Serial.println("0 = Imams Shafi, Hanbali and Maliki  ");
    Serial.println("1 = Imam Hanfi                       ");
    
    do{
    }while(Serial.available() < 1);
    ch = Serial.read();
    
    if( ch != '0' && ch != '1' )
      Serial.println("Invalid Input Option");
    
  }while(ch != '0' && ch != '1' );
  
  asr_juristic = ch & 0x0F;

  struct tm current_date;
  
  current_date.tm_sec   = 38;           /** < seconds after the minute - [ 0 to 59 ] */
  current_date.tm_min   = 29;           /** < minutes after the hour   - [ 0 to 59 ] */
  current_date.tm_hour  = 14;           /** < hours since midnight     - [ 0 to 23 ] */
  current_date.tm_mday  = 30;           /** < day of the month         - [ 1 to 31 ] */
  current_date.tm_wday  =  2;           /** < days since Sunday        - [ 0 to  6 ] */
  current_date.tm_mon   =  5;           /** < months since January     - [ 0 to 11 ] */
  current_date.tm_year  = 2020 - 1900;  /** < years since 1900                       */
  
  time_t date = mktime(&current_date);
  
  double times[TimesCount];
  Serial.print("Date          : ");
  Serial.println(ctime(&date));
  Serial.print("Time Zone     : ");
  Serial.println(Time_Zone);
  Serial.print("Latitude      : ");
  Serial.println(latitude);
  Serial.print("Longitude     : ");
  Serial.println(longitude);
  
  
  get_prayer_times(date, latitude, longitude, Time_Zone, times);
  
    Serial.print(TimeName[0]); Serial.print("    : ");
    Serial.println(float_time_to_time12(times[0]).c_str());
  
    Serial.print(TimeName[1]); Serial.print(" : ");
    Serial.println(float_time_to_time12(times[1]).c_str());

    Serial.print(TimeName[2]); Serial.print("   : ");
    Serial.println(float_time_to_time12(times[2]).c_str());

    Serial.print(TimeName[3]); Serial.print("     : ");
    Serial.println(float_time_to_time12(times[3]).c_str());

    Serial.print(TimeName[4]); Serial.print("  : ");
    Serial.println(float_time_to_time12(times[4]).c_str());

    Serial.print(TimeName[5]); Serial.print(" : ");
    Serial.println(float_time_to_time12(times[5]).c_str());

    Serial.print(TimeName[6]); Serial.print("    : ");
    Serial.println(float_time_to_time12(times[6]).c_str());

    Serial.println("Press any key to continue . . .");

    do{
    }while(Serial.available() < 1);
    ch = Serial.read();
    

}









String two_digits_format(int num){
    char tmp[16];
    tmp[0] = '\0';
    sprintf(tmp, "%2.2d", num);
    return String(tmp);
}
static String int_to_string(int num)
{
    char tmp[16];
    tmp[0] = '\0';
    if (num>=0 && num<=9) sprintf(tmp, "0%d", num);
    else sprintf(tmp, "%d", num);
    return String(tmp);
}

static double fix_hour(double a){
    a = a - 24.0 * floor(a / 24.0);
    a = a < 0.0 ? a + 24.0 : a;
    return a;
}
static void get_float_time_parts(double time, int& hours, int& minutes){
    time = fix_hour(time + 0.5 / 60);   // add 0.5 minutes to round
    hours = floor(time);
    minutes = floor((time - hours) * 60);
}
String float_time_to_time24(double Time){
    if(isnan(Time))
      return String();
    int hours, minutes;
    get_float_time_parts(Time, hours, minutes);
    return two_digits_format(hours) + ':' + two_digits_format(minutes);
}
String float_time_to_time12(double Time, bool no_suffix = false){
  if (isnan(Time))
    return String();
  int hours, minutes;
  get_float_time_parts(Time, hours, minutes);
  const char* suffix = hours >= 12 ? " PM" : " AM";
  hours = (hours + 12 - 1) % 12 + 1;
  return int_to_string(hours) + ':' + two_digits_format(minutes) + (no_suffix ? "" : suffix);
}
double deg2rad(double d){
    return d * M_PI / 180.0;
}
double rad2deg(double r){
    return r * 180.0 / M_PI;
}
static double dsin(double d){
    return sin(deg2rad(d));
}
static double dcos(double d){
    return cos(deg2rad(d));
}
static double dtan(double d){
    return tan(deg2rad(d));
}
static double darcsin(double x){
    return rad2deg(asin(x));
}
static double darccos(double x){
    return rad2deg(acos(x));
}
static double darctan(double x){
    return rad2deg(atan(x));
}
static double darctan2(double y, double x){
    return rad2deg(atan2(y, x));
}
static double darccot(double x){
    return rad2deg(atan(1.0 / x));
}
static double fix_angle(double a){
    a = a - 360.0 * floor(a / 360.0);
    a = a < 0.0 ? a + 360.0 : a;
    return a;
}
static double time_diff(double time1, double time2){
    return fix_hour(time2 - time1);
}
void sun_position(double jd, double &D, double &Eq_t){
    double d = jd - 2451545.0;  // jd is the given Julian date 
    double g = fix_angle(357.529 + 0.98560028 * d);
    double q = fix_angle(280.459 + 0.98564736 * d);
    double L = fix_angle(q + 1.915 * dsin(g) + 0.020 * dsin(2 * g));
    double R = 1.00014 - 0.01671 * dcos(g) - 0.00014 * dcos(2 * g);
    double e = 23.439 - 0.00000036 * d;
    double RA = darctan2(dcos(e) * dsin(L), dcos(L)) / 15.0;
    D = darcsin(dsin(e) * dsin(L));  // declination of the Sun
    RA = fix_hour(RA);
    Eq_t = q / 15.0 - RA;      // equation of time
}
double equation_of_time(double jd){
    double D;
    double Eq_t;
    sun_position(jd, D, Eq_t);
    return Eq_t;
}
double sun_declination(double jd){
    double D;
    double Eq_t;
    sun_position(jd, D, Eq_t);
    return D;
}
double compute_mid_day(double _t){
    double t = equation_of_time(julian_date + _t);
    double z = fix_hour(12 - t);
    return z;
}
double compute_time(double g, double t){
    double d = sun_declination(julian_date + t);
    double z = compute_mid_day(t);
    double v = 1.0 / 15.0 * darccos((-dsin(g) - dsin(d) * dsin(latitude)) / (dcos(d) * dcos(latitude)));
    return z + (g > 90.0 ? - v :  v);
}
void day_portion(double times[]){
    for (int i = 0; i < TimesCount; ++i){
      times[i] /= 24.0;
    }
}
double compute_asr(int Step, double t){
    double d = sun_declination(julian_date + t);
    double g = -darccot(Step + dtan(fabs(latitude - d)));
    return compute_time(g, t);
}
void compute_times(double times[]){
    day_portion(times);
    times[Fajr]    = compute_time(180.0 - method_params[calc_method].fajr_angle, times[Fajr]);
    times[Sunrise] = compute_time(180.0 - 0.833, times[Sunrise]);
    times[Dhuhr]   = compute_mid_day(times[Dhuhr]);
    times[Asr]     = compute_asr(1 + asr_juristic, times[Asr]);
    times[Sunset]  = compute_time(0.833, times[Sunset]);
    times[Maghrib] = compute_time(method_params[calc_method].maghrib_value, times[Maghrib]);
    times[Isha]    = compute_time(method_params[calc_method].isha_value, times[Isha]);
}
double night_portion(double angle){
    switch (adjust_high_lats)
    {
      case AngleBased:
        return angle / 60.0;
      case MidNight:
        return 1.0 / 2.0;
      case OneSeventh:
        return 1.0 / 7.0;
      default:
        // Just to return something!
        // In original library nothing was returned
        // Maybe I should throw an exception
        // It must be impossible to reach here
        return 0;
    }
  }
void adjust_high_lat_times(double times[]){
    double night_time = time_diff(times[Sunset], times[Sunrise]);   // sunset to sunrise

    // Adjust Fajr
    double fajr_diff = night_portion(method_params[calc_method].fajr_angle) * night_time;
    if (isnan(times[Fajr]) || time_diff(times[Fajr], times[Sunrise]) > fajr_diff)
      times[Fajr] = times[Sunrise] - fajr_diff;

    // Adjust Isha
    double isha_angle = method_params[calc_method].isha_is_minutes ? 18.0 : method_params[calc_method].isha_value;
    double isha_diff = night_portion(isha_angle) * night_time;
    if (isnan(times[Isha]) || time_diff(times[Sunset], times[Isha]) > isha_diff)
      times[Isha] = times[Sunset] + isha_diff;

    // Adjust Maghrib
    double maghrib_angle = method_params[calc_method].maghrib_is_minutes ? 4.0 : method_params[calc_method].maghrib_value;
    double maghrib_diff = night_portion(maghrib_angle) * night_time;
    if (isnan(times[Maghrib]) || time_diff(times[Sunset], times[Maghrib]) > maghrib_diff)
      times[Maghrib] = times[Sunset] + maghrib_diff;
  }
void adjust_times(double times[]){
    for (int i = 0; i < TimesCount; ++i)
      times[i] += Time_Zone - longitude / 15.0;
    
    times[Dhuhr] += dhuhr_minutes / 60.0;   // Dhuhr
    
    if (method_params[calc_method].maghrib_is_minutes)    // Maghrib
      times[Maghrib] = times[Sunset] + method_params[calc_method].maghrib_value / 60.0;
    
    times[Isha];

    if (method_params[calc_method].isha_is_minutes)   // Isha
      times[Isha] = times[Maghrib] + method_params[calc_method].isha_value / 60.0;

    if (adjust_high_lats != None)
      adjust_high_lat_times(times);
  }
void compute_day_times(double times[]){
    double default_times[] = { 5, 6, 12, 13, 18, 18, 18 };    // default times
    for (int i = 0; i < TimesCount; ++i)
      times[i] = default_times[i];

    for (int i = 0; i < NUM_ITERATIONS; ++i)
      compute_times(times);

    adjust_times(times);
  }
double get_julian_date(int Year, int Month, int Day){
    if (Month <= 2)
    {
      Year -= 1;
      Month += 12;
    }

    double a = floor(Year / 100.0);
    double b = 2 - a + floor(a / 4.0);
    double c = floor(365.25 * (Year + 4716)) + floor(30.6001 * (Month + 1)) + Day + b - 1524.5;
    
    return c;
  }
  
void get_prayer_times(int Year, int Month, int Day, double _latitude, double _longitude, double _timezo, double times[]){
    latitude = _latitude;
    longitude = _longitude;
    Time_Zone = _timezo;
    julian_date = get_julian_date(Year, Month, Day);
    julian_date = julian_date - longitude / (double) (15 * 24);
    compute_day_times(times);
  }
void get_prayer_times(time_t date, double latitude, double longitude, double Tzone, double times[]){
    tm* t = localtime(&date);
    get_prayer_times((1900 + t->tm_year), (t->tm_mon + 1), (t->tm_mday), latitude, longitude, Tzone, times);
  }
