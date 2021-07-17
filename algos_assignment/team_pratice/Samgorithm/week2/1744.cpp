#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, zero, one;
vector<int>positive, negative;

int main() {
   cin >> n;
   for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      if (tmp == 0)zero++;
      else if (tmp == 1)one++;
      else if (tmp < 0)negative.push_back(tmp);
      else positive.push_back(tmp);
   }

   if (positive.size() % 2 == 1) {
      positive.push_back(1);
   }

   if (negative.size() % 2 == 1) {
      if (zero == 0)negative.push_back(1);
      else negative.push_back(0);
   }

   sort(positive.begin(), positive.end());
   sort(negative.begin(), negative.end());

   int sum = one;
   for (int i = 0; i < positive.size(); i += 2)
      sum += positive[i] * positive[i + 1];
   for (int i = 0; i < negative.size(); i += 2)
      sum += negative[i] * negative[i + 1];

   cout << sum << "\n";

   return 0;
}
