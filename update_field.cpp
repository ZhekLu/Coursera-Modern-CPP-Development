#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

bool operator== (const Date &lhs, const Date &rhs) {
  return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

std::ostream& operator<< (ostream& out, const Date &dt) {
  out << dt.year << '-' << dt.month << '-' << dt.day;
  return out;
}

bool operator== (const Time &lhs, const Time &rhs) {
  return tie(lhs.hours, lhs.minutes) == tie(lhs.hours, lhs.minutes);
}

std::ostream& operator<< (ostream &out, const Time &tm) {
  out << tm.hours << ':' << tm.minutes;
  return out;
}

#define UPDATE_FIELD(ticket, field, values) {\
    map<string,string>::const_iterator it = values.find(#field);      \
    if (it != values.end())        \
        ChangeValue(ticket.field, it->second);  \
}

void ChangeValue(Date& toChange, const string& str) {
  std::istringstream stream(str);
  string token;
  getline(stream, token, '-') >> toChange.month;
  toChange.year = stoi(token);
  getline(stream, token, '-') >> toChange.day;
}

void ChangeValue(Time& toChange, const string& str) {
  std::istringstream stream(str);
  string token;
  getline(stream, token, ':') >> toChange.minutes;
  toChange.hours = stoi(token);
}

void ChangeValue(string& toChange, const string& str) {
  toChange = str;
}

void ChangeValue(int& toChange, const string& str){
  istringstream stream(str);
  stream >> toChange;
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}