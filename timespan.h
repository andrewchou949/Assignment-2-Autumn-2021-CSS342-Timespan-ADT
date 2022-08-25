//
// Created by Yusuf Pisan on 4/2/18.
// Edited and added more function by Andrew Chou 10/16/2021.

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:

  // default constructor if not param is provided.
  TimeSpan();
  // explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
  explicit TimeSpan(double hour, double minute, double second);

  //additional method to convert timespan (hours, minutes and seconds) to 'seconds' unit.
  double convertTSToSecs() const;
  
  // adding method
  // passing by constant, not changing value
  TimeSpan operator+(const TimeSpan &ts) const;

  // subtract method
  // passing by constant, not changing value
  TimeSpan operator-(const TimeSpan &ts) const;

  // check equality
  // return true if == or false otherwise
  bool operator==(const TimeSpan &ts) const;

  // check if not equal
  // return true if != or false otherwise
  bool operator!=(const TimeSpan &ts) const;

  // multiply timespan by an unsigned number
  // passing by constant, not changing value
  TimeSpan operator*(unsigned int number) const;

  // TODO(student)
  // to add operator+=, operator-=, operator<, operator>, operator<=, operator>=

  //Adding timespan and changing value (not constant)
  TimeSpan operator+=(TimeSpan &ts);

  //subtract timespan and changing value (not constant)
  TimeSpan operator-=(TimeSpan &ts);

  //checking if the one timespan is < than others
  //return true if < or false otherwise
  bool operator<(const TimeSpan &ts) const;

  //checking if the one timespan is > than others
  //return true if > or false otherwise
  bool operator>(const TimeSpan &ts) const;

  //checking if the one timespan is <= than others
  //return true if <= or false otherwise
  bool operator<=(const TimeSpan &ts) const;

  //checking if the one timespan is >= than others
  //return true if >= or false otherwise
  bool operator>=(const TimeSpan &ts) const;

  // hour component of timespan
  // give permission to get hours (private data members)
  int getHour() const;

  // minute component of timespan
    // give permission to get mins (private data members)
  int getMinute() const;

  // second component of timespan
  // give permission to get seconds (private data members)
  int getSecond() const;

  // true if timespan is 0 or larger
  // to check the timespan if it is positive or not.
  bool isPositive() const;

private:
  double hours; 
  double mins; 
  double secs;
  //To keep track of the positive or non positive status of timespan
  bool positive;

};

#endif // ASS2_TIMESPAN_H