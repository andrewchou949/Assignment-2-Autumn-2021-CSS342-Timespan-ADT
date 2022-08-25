//
// Created by Yusuf Pisan on 4/2/18.
// Completed method details by Andrew Chou 10/16/2021
//

#include "timespan.h"
#include <iomanip>

using namespace std;

//friend ostream method
//Pre: no output being printed
//post: print the hours, minutes and second to console to show the info of the object created from constructor below
ostream &operator<<(ostream &out, const TimeSpan &ts) {
  //if the timespan is positive, no '-' sign needed
  if(ts.positive){
    out << ts.hours << ":" << std::setw(2) << std::setfill('0') << ts.mins << ":" << std::setw(2) << std::setfill('0') << ts.secs;
  }
  //else, print '-' before hours
  else{
    out << "-" << ts.hours << ":" << std::setw(2) << std::setfill('0') << ts.mins << ":" << std::setw(2) << std::setfill('0') << ts.secs;
  }
  return out;
}

//default constructor
//pre: no object created
//post: timespan object created with 0 hours, 0 mins, 0 secs
TimeSpan::TimeSpan(){
  hours = 0;
  mins = 0;
  secs = 0;
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
// pre: no object created
// post: create timespan object with hour, minute and second provided as param
//        convert the minute and second to appropriate format (only 0 to 59 allowed)
TimeSpan::TimeSpan(double hour, double minute, double second) {
  int totalSecs = hour * 3600 + minute * 60 + second;
  //Getting the accurate decimal place with double data type instead
  //Or the positive or not positive for total mins of TS will be incorrect to truncation
  double totalHourInMins = hour * 60 + minute + second / 60.0;
  long minsTemp = totalSecs / 60;
  secs = abs(totalSecs % 60);
  //The last part must be a float to show accurate addition here
  mins = minsTemp % 60;
  //For hours
  hours = hour + (minute / 60) + (second / 3600);
  // convert hours to int type (to omit decimal place)
  hours = (int) hours;
  //detect if timespan is positive or not, if positive, turn bool to true (1)
  if(totalHourInMins > 0){
    positive = true;
  }
  //else turn the bool to false (0)
  else{
    positive = false;
  }
}

// hour component
//pre: no access to hour private data
//post: allow client to get hour data
int TimeSpan::getHour() const {
  return hours;
}

// minute component
//pre: no access to mins private data
//post: allow client to get mins data
int TimeSpan::getMinute() const {
  return mins;
}

// second component
//pre: no access to secs private data
//post: allow client to get secs data
int TimeSpan::getSecond() const {
  return secs;
}

// true if timespan is 0 or larger
// pre: no access for positive timespan or not
// post:  able to know if timespan is positive or otherwise
bool TimeSpan::isPositive() const { 
  return positive; 
}

//Convert any TS to all seconds
//pre: all timespan are in hours, mins ,secs format
//post: convert timespan to secs
double TimeSpan::convertTSToSecs() const {
  return hours * 3600 + mins * 60 + secs;
}

// add (not changing ref)
// pre: none
// post: adding the timespan in client cpp, no data member being changed (const)
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  double sumSec = convertTSToSecs() + ts.convertTSToSecs();
  TimeSpan tsSum(0, 0, sumSec);
  return tsSum;
}

// subtract (not changing ref)
// pre: none
// post: subtracting the timespan in client cpp, no data member being changed (const)
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  double subSec = convertTSToSecs() - ts.convertTSToSecs();
  TimeSpan tsSub(0, 0, subSec);
  return tsSub;
}

// multiply with an integer
// pre: none
// post: multiply the timespan with int number in client cpp, no data member being changed (const)
TimeSpan TimeSpan::operator*(unsigned int number) const {
  double productRes = convertTSToSecs() * number;
  TimeSpan tsLarge(0, 0, productRes);
  return tsLarge;
}

// equality ==
// pre: none
// post: check if timespan are equal
bool TimeSpan::operator==(const TimeSpan &ts) const {
  return (convertTSToSecs() == ts.convertTSToSecs()); 
}

// inequality !=
// pre: none
// post: check if timespan are inequal
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  return (convertTSToSecs() != ts.convertTSToSecs()); 
}

//testing if >
// pre: none
// post: check if one timespan is bigger than others(ts, param)
bool TimeSpan::operator>(const TimeSpan &ts) const{
  return (convertTSToSecs() > ts.convertTSToSecs());
}

//testing if <
// pre: none
// post: check if one timespan is smaller than others(ts, param)
bool TimeSpan::operator<(const TimeSpan &ts) const{
  return (convertTSToSecs() < ts.convertTSToSecs());
}

//testing if >=
// pre: none
// post: check if one timespan is bigger or equal to others(ts, param)
bool TimeSpan::operator>=(const TimeSpan &ts) const{
  return (convertTSToSecs() >= ts.convertTSToSecs());
}

//testing if <=
// pre: none
// post: check if one timespan is smaller or equal to others(ts, param)
bool TimeSpan::operator<=(const TimeSpan &ts) const{
  return (convertTSToSecs() <= ts.convertTSToSecs());
}

//Addition: changing ref
// pre: none
// post: adding one timespan to another(ts param) and change data member
TimeSpan& TimeSpan::operator+=(TimeSpan &ts){
  double sum = convertTSToSecs() + ts.convertTSToSecs();
  TimeSpan addition(0, 0, sum);
  return addition;
}

//Sub: changing ref
// pre: none
// post: subtracting one timespan to another(ts param) and change data member
TimeSpan& TimeSpan::operator-=(TimeSpan &ts){
  double sub = convertTSToSecs() - ts.convertTSToSecs();
  TimeSpan subtract(0, 0, sub);
  return subtract;
}