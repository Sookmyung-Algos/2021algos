#include <iostream>
#include <vector>
#include <queue>
#include <string.h> // memset
using namespace std;

vector<int> network[200001];
queue<int> q;
queue<int> tempq;
int rumor[200001]; // visit
int cnt[200001];
int N, M, p, hour = 0;

void check() {
   hour++;
   while (!tempq.empty()) {
      int temp = tempq.front();
      tempq.pop();

      if (rumor[temp] != -1 || cnt[temp] == 0) continue; // 이미 루머를 믿거나 주변인 중 루머를 믿는 사람이 0

      double half = network[temp].size() / 2.0;
      if (cnt[temp] >= half) {
         q.push(temp);
         rumor[temp] = hour;
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   memset(rumor, -1, sizeof(rumor));
   
   cin >> N;
   for (int i = 1; i <= N; i++) {
      while (1) {
         cin >> p;
         if (p == 0) break;
         network[i].push_back(p);
      }
   }
