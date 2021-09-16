#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstring>
#include <math.h>
#include <queue>
#define MAX 1000001

using namespace std;


int n;  //도시의 수
int m;  //여행 계획 도시의 수
int arr[2003][2003];
vector <int> group[2003];
vector <int> plan;
int getBoss(int i) {
   if (group[i].size() == 0) return i;

   int ret = getBoss(group[i][0]);
   return ret;
}

void setGroup(int t1, int t2) {
   int a = getBoss(t1);
   int b = getBoss(t2);

   if (a == b) return;
   group[b].push_back(a);

}


int main() {
   cin.tie(0);
   cout.tie(0);
   ios_base::sync_with_stdio(false);

   cin >> n >> m;

   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         cin >> arr[i][j];
      }
   }
   
   for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      plan.push_back(a);
   }

   for (int i = 1; i <= n; i++) {
      for (int j =1; j <= n; j++) {
         if (arr[i][j] == 1) {
            //if (getBoss(i) == getBoss(j)) continue;
            setGroup(j, i);
         }
      }
   }
   
   
   int boss = getBoss(plan[0]);
   for (int i = 1; i < m; i++) {
      int b = getBoss(plan[i]);
      if (boss != b) {
         cout << "NO";
         return 0;
      }
   }
   cout << "YES";
   return 0;

}
