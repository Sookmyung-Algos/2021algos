#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void add(int sum, int num) {
   if (sum > num)
      return;
   else if (sum == num) {
      cnt++;
      return;
   }
   else {      // n값보다 작은 합에 대해서
      for (int i = 1; i <= 3; i++)   
         add(sum + i, num);         // 1부터 3까지 하나씩 더하면서 조건 검사.
   }
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int T, n;
   vector<int> cntArr;

   cin >> T;
   
   for (int i = 0; i < T; i++) {
      cnt = 0;   //각 테스트 케이스마다 카운트 값 초기화
      cin >> n;
      add(0, n);      //sum이 n이 될때 카운트 증가시키는 함수
      cntArr.push_back(cnt);
   }

   //cnt 값들 출력
   for(int i=0; i<cntArr.size(); i++){
      cout << cntArr[i] << '\n';   
   }

   return 0;
}
