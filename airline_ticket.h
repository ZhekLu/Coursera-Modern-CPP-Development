#pragma once

#include <string>
using namespace std;

struct Date {
  int year, month, day;

  // Date(int x, int y, int z) { year = x, month = y, day = z; }
  // Date(int x){}
};


struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};