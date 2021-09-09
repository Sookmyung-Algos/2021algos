#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int N, K, M, V, C;
   cin >> N >> K;

   vector<pair<int, int>> jewel;
   for (int i = 0; i < N; i++) {
      cin >> M >> V;
      jewel.push_back({ M, V });
   }

   vector<int> bag;
   for (int i = 0; i < K; i++) {
      cin >> C;
      bag.push_back(C);
   }
   sort(jewel.begin(), jewel.end());
   sort(bag.begin(), bag.end());

   priority_queue<int> pq;
   long long sum = 0;
   for (int n = 0, i = 0; n < K; n++) {
      while (i < N && bag[n] >= jewel[i].first)
         pq.push(jewel[i++].second);

      if (!pq.empty()) {
         sum += pq.top();
         pq.pop();
      }
   }
   cout << sum;
}
