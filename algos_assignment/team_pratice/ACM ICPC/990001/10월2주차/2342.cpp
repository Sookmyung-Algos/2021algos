#include <iostream>
#include <vector>
#define INF 400001
using namespace std;

vector<int> v;
int dp[5][5][100001];

int arr[5][5] = {
   { 0, 2, 2, 2, 2 },
   { 0, 1, 3, 4, 3 },
   { 0, 3, 1, 3, 4 },
   { 0, 4, 3, 1, 3 },
   { 0, 3, 4, 3, 1 }
};

int movefunction(int l, int r, int cnt) {
   if (cnt == v.size()) return 0;

   if (dp[l][r][cnt]) return dp[l][r][cnt];

   return dp[l][r][cnt] = min(movefunction(v[cnt], r, cnt + 1) + arr[l][v[cnt]],
         movefunction(l, v[cnt], cnt + 1) + arr[r][v[cnt]]);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int x;
   while (1) {
      cin >> x;
      if (!x) break;
      v.push_back(x);
   }

   cout << movefunction(0, 0, 0) << '\n';

   return 0;
}
