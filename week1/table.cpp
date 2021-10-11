#include "test_runner.h"
using namespace std;

template<typename T>
class Table {
public:
   Table(size_t rows, size_t cols) {
       if (!rows || !cols) {
           this->rows = this->cols = 0;
       }
       else {
           base.resize(rows);
           for (int i = 0; i < rows; i++) {
              base[i].resize(cols);
           this->rows = rows;
           this->cols = cols;
       }
       }
   }


   pair<size_t, size_t> Size() const {
       return make_pair(rows, cols);
   }

   void Resize(size_t newRows, size_t newCols) {
       vector<vector<T>> newBase(newRows);
       for (int i = 0; i < newRows; i++) {
           newBase[i].resize(newCols);
       }
       
       for (int i = 0; i < newRows && i < rows; i++)
           for(int j = 0; j < newCols && j < cols; j++)
               newBase[i][j] = base[i][j];
       
       base = newBase;
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