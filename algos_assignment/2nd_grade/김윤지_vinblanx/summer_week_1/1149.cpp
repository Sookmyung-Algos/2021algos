#include <iostream>
#include <algorithm>

using namespace std;

int house[1001][3];

int main() {
    int N;
    int cost[3];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
  
    cin >> N;
  
    for(int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i-1][1],house[i-1][2]) + cost[0];
        house[i][1] = min(house[i-1][0],house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][1],house[i-1][0]) + cost[2];
    }
    cout << min(house[N][2],min(house[N][0],house[N][1]));
  
  return 0;
}
