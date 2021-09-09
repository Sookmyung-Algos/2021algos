#include <iostream>
#include <vector>

using namespace std;

int main() {
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   int N;
   cin >> N; //풍선 개수
   vector<pair<int, int>> v;

   for (int i = 1; i <= N; i++) { 
      int N;
      cin >> N;

      v.push_back(make_pair(i, N)); //풍선 번호, 종이 숫자
   }

   while (v.empty() != true) {
      cout << v.front().first << " ";
      int a = v.front().second;
      v.erase(v.begin());

      if (a < 0) {  //음수이면, 맨 뒤를 맨 앞으로
         for (int i = 0; i < abs(a); i++) {
            v.insert(v.begin(), v.back());
            v.erase(v.end());
         }
      }
      else {  //양수이면, 맨 앞을 맨 뒤로
         for (int i = 0; i < a - 1; i++) {
            v.push_back(v.front());
            v.erase(v.begin());
         }
      }
   }
   return 0;
}
