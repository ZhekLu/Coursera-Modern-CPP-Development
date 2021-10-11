#include "test_runner.h"
using namespace std;

template<typename T>
class Table {
public:
   Table(size_t rows, size_t cols) {
        if (!rows || !cols) 
            rows = cols = 0;
        Resize(rows, cols);
   }


   pair<size_t, size_t> Size() const {
       return make_pair(rows, cols);
   }

   void Resize(size_t newRows, size_t newCols) {
       base.resize(newRows);
       for (int i = 0; i < newRows; i++) 
            base[i].resize(newCols);

       rows = newRows;
       cols = newCols;
   }

   vector<T>& operator[] (const int index) {
       return base[index];
   }

   const vector<T>& operator[] (const int index) const {
       return base[index];
   }

private:
   size_t rows;
   size_t cols;
   vector<vector<T>> base;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}