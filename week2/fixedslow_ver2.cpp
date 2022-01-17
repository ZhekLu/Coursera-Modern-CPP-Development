#include <iomanip>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

class ReadingManager {
public:
  ReadingManager()
  : pages_count(MAX_PAGES_COUNT_ + 1, 0) {}

  void Read(int user_id, int page_count) {
    const auto user = userid_pages.find(user_id);
    if (user != userid_pages.end())
      pages_count[(*user).second]--;
    
    userid_pages[user_id] = page_count;
    pages_count[page_count]++;
  }

  double Cheer(int user_id) const {
    if (userid_pages.find(user_id) == userid_pages.end())
      return 0;
    if (GetUserCount() == 1)
      return 1; 
    return CountBelow(userid_pages.at(user_id)) * 1. / (GetUserCount() - 1);
  }

private:
    static const int MAX_PAGES_COUNT_ = 1'000;

  unordered_map<int, int> userid_pages;
  vector<int> pages_count;

  int GetUserCount() const {
    return userid_pages.size();
  }

  int CountBelow(int pages) const {
      int below_num = 0;
      for(int i = 0; i < pages; i++)
        below_num += pages_count[i];
      return below_num;
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}