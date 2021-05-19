#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1001
int D[MAX];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, d, w;
	cin >> n;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		a.push_back({ w,d }); //점수 마감일수 순
	}

	sort(a.begin(), a.end(), greater<pair<int, int> >()); //정렬

	for (int i = 0; i < n; ++i) {
		int temp = a[i].second; //마지막 마감일
		while (temp >= 1) {
			if (D[temp] == 0) { // 그 마감일에 과제가 없으면 점수가 더 큰 과제를 넣음
				D[temp] = a[i].first; 
				break;
			}
			else {
				temp--; //아니면 과제 없는 날이 나올때까지 줄여나감
			}

		}

	}

	int ans = 0;
	for (int i = 1; i <= MAX; i++) { //마감일의 최대인 Max까지 반복문을 돌려 최종 점수 계산
		ans += D[i];
	}

	cout << ans << '\n'; // 최종 점수


	return 0;
}
