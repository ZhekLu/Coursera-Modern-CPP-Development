#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;

bool operator== (const Date &lhs, const Date &rhs) {
  return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

ostream& operator<< (ostream& out, const Date &dt) {
  out << dt.year << '-' << dt.month << '-' << dt.day;
  return out;
}

istream& operator>> (istream& is, Date& toRecord) {
  is >> toRecord.year;
  is.ignore(1);
  is >> toRecord.month;
  is.ignore(1);
  is >> toRecord.day;
  return is;
}

bool operator== (const Time &lhs, const Time &rhs) {
  return tie(lhs.hours, lhs.minutes) == tie(lhs.hours, lhs.minutes);
}

ostream& operator<< (ostream &out, const Time &tm) {
  out << tm.hours << ':' << tm.minutes;
  return out;
}

istream& operator>> (istream& is, Time& toRecord) {
  is >> toRecord.hours;
  is.ignore(1);
  is >> toRecord.minutes;
  return is;
}

#define UPDATE_FIELD(ticket, field, values) {                         \
    map<string,string>::const_iterator it = values.find(#field);      \
    if (it != values.end())  {                                        \
      istringstream is(it->second);                                   \
      is >> ticket.field;                                             \
    }                                                                 \
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