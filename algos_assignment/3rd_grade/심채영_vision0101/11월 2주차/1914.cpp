#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;
vector<pair<int, int>> v;

void Hanoi(int num, int from, int by, int to) {
  if(num == 1) {
    v.push_back({from, to});
  }
  else {
    Hanoi(num - 1, from, to, by);
    v.push_back({from, to});
    Hanoi(num - 1, by, from, to);
  }
}

int main() {
  cin >> N;
  Hanoi(N, 1, 2, 3);

  cout << pow(2, N)-1 << endl;

  for(int i = 0; i < v.size(); i++){
    cout << v[i].first << " " << v[i].second << "\n";
  }
  return 0;
} 
