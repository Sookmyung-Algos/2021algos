#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;

int main() {

  int n;
  vector<int> v;

  while(cin >> n) {
    v.clear();
    for(int i=1; i<=n; i++) {
      int cost;
      cin >> cost;

      if(v.empty() || v.back() < cost) {
        v.push_back(cost);
      }
      else {
        int index = lower_bound(v.begin(), v.end(), cost) - v.begin();
        v[index] = cost;
      }
    }
    cout << v.size() <<'\n';
  }
} 


