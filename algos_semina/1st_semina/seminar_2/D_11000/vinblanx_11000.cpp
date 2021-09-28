#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
 
int main()
{
   pair<int, int> p[200001];
   priority_queue<int, vector<int>, greater<int>> pq;
 
   int N;
   cin >> N;
 
   for (int i = 0; i < N; ++i) {
      cin >> p[i].first >> p[i].second;
   }
 
   sort(p, p + N);
 
   pq.push(p[0].second);
 
   for (int i = 1; i < N; ++i) {
      if (pq.top() <= p[i].first) {
         pq.pop();
         pq.push(p[i].second);
      }
      else {
         pq.push(p[i].second);
      }
   }
 
   cout << pq.size();
}
