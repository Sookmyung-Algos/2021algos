#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> line[300001];
int chk[300001];

int main() {
   int start, end, n, idx = 0;
  
   cin >> n;
   for (int i = 0; i < n - 2; i++) {
      cin >> start >> end;
      line[start].push_back(end);
      line[end].push_back(start);
   }
  
   queue<int> q;
  
   q.push(1);
   chk[1] = 1;
  
   while (!q.empty()) {
      int c_idx = q.front();
      q.pop();
     
      for (int i = 0; i < line[c_idx].size(); i++) {
         int next = line[c_idx][i];
        
         if (chk[next] == 0) {
            chk[next] = 1;
            q.push(next);
         }
      }
   }
  
   for (int i = 1; i <= n; i++) {
      if (chk[i] == 0) {
         idx = i;
         break;
      }
   }
  
   cout << 1 << " " << idx;
}
