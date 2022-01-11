#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int before = dict.size();
    dict.insert(words.begin(), words.end());
    return dict.size() - before;
  }

  vector<string> KnownWords() {
    return {dict.begin(), dict.end()};
  }
};