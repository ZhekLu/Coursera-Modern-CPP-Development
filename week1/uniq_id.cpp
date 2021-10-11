#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define generateID_helper(x) ID##x
#define generateID(x) generateID_helper(x)
#define UNIQ_ID generateID(__LINE__)
#define getstr(x) #x
int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}