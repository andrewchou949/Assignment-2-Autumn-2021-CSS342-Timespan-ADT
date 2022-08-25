TimeSpan
Goals: Understanding operator overloading

Assignment 2 for CSS 342 Autumn Quarter 2021 UWB

This assignment 2 simulates a Timespan ADT class to illustrate the basic elements of class such as overloading operators, constructor, copy constructor, destructor, basic getters, setters, etc.

Design and implement TimeSpan class which represents a duration in hours, minutes and seconds.

Displayed       Meaning
2:12:07         2 hours, 12 minutes, 7 seconds
-0:10:43        Minus 10 minutes and 43 seconds
The seconds and minutes have to be between 0 and 59. The hours can be 0 to any number. The constructor for TimeSpan can take 0 or 3 parameters. In addition to integer value, the constructor should also be able to handle double values and convert them as accurately as possible

TimeSpan(1.5, -10, 93)	same as 1:21:33
TimeSpan(1.5)		    same as 1:30:00
Compile and Run

# quick compile for testing
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp

# comprehensive tests
./create-output.sh > output.txt 2>&1
