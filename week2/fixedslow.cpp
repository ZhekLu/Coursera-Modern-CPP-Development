#include <iomanip>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;

class ReadingManager {
public:
  ReadingManager(){
  }

  void Read(int user_id, int page_count) {
    const auto user = userid_pages.find(user_id);
    if (user != userid_pages.end())
      pages_userid.erase(pair((*user).second, user_id));
    userid_pages[user_id] = page_count;
    pages_userid.insert(pair(page_count, user_id));
  }

  double Cheer(int user_id) const {
    if (userid_pages.find(user_id) == userid_pages.end())
      return 0;
    if (GetUserCount() == 1)
      return 1;
    // cerr << "Cheer " << user_id << endl;
    const auto first_better = pages_userid.lower_bound(pair(userid_pages.at(user_id), -1));
    // cerr << "first better: " << (*first_better).first << ' ' << (*first_better).second << endl;
    const int below_competitors = distance(pages_userid.begin(), first_better);
    // cerr << "below = " << below_competitors << endl;
    // cerr << "res = " << below_competitors * 1. / (GetUserCount() - 1);
    return below_competitors * 1. / (GetUserCount() - 1);
  }

private:
  unordered_map<int, int> userid_pages;
  set<pair<int, int>> pages_userid;

  int GetUserCount() const {
    return userid_pages.size();
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