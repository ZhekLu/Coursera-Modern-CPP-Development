#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

#define LOG(logger, message) \
    logger.Log(message, __FILE__, __LINE__);

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }

  void Log(const string& message, string file = __FILE__, int line = __LINE__);

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

void Logger::Log(const string& message, string file, int line) {
    if (log_file) {
        os << file;
        if (log_line)
            os << ' ' << line << ' ';
        else  
            os << ' ';
    }
    else if (log_line) {
        os << "Line " << line << ' ';
    }

    os << message << '\n'; 
    
}

void TestLog() {
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}