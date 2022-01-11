#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "learner.cpp"
#include "profile.h"

int main() {
  Learner learner;
  string line;
  int i = 100;
  {
    LOG_DURATION("Reading")
    while (i-- && getline(cin, line)) {
      vector<string> words;
      stringstream ss(line);
      string word;
      while (ss >> word) {
        words.push_back(word);
      }
      {
        LOG_DURATION("Lear")
        cout << learner.Learn(words) << "\n";
      }
    }
  }
  cout << "=== known words ===\n";

  {
    LOG_DURATION("KNOWN WORDS")
    for (auto word : learner.KnownWords()) {
      cout << word << "\n";
    }
  }
}