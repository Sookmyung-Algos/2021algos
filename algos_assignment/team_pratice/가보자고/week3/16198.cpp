#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, tmp;
int result = 0;
int maxEnergy, tmpTotalEnergy;
vector<int> marbles;

void solution() {
   if (marbles.size() == 2 ) {  // 모든 경우의 수 계산 완료
      if (maxEnergy < tmpTotalEnergy)// 그 값이 현재의 최댓값보다 크면 최댓값 갱신
         maxEnergy = tmpTotalEnergy;
      return;
   }
   for (int i = 1; i < marbles.size() - 1; i++) {  // 첫번째, 마지막 공 제외
      int curMarble = marbles[i];  // 현재 구슬 에너지 저장
      tmpTotalEnergy += (marbles[i - 1] * marbles[i + 1]);  // i번째 구슬 제거했을 때 에너지
      marbles.erase(marbles.begin() + i);  // i번째 구슬을 실제 벡터에서 제거
      solution();  // 이 상태에서 바뀐 배열에 대해 다시 호출
      marbles.insert(marbles.begin() + i, curMarble);  // i번째를 다시 추가
      tmpTotalEnergy -= (marbles[i - 1] * marbles[i + 1]);  // 다시 추가됐으니까 에너지값에선 뺌
   }
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> tmp;
      marbles.push_back(tmp);
   }
   solution();
   cout << maxEnergy;

   return 0;
}
