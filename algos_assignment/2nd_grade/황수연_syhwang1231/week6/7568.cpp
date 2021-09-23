// 7568: 덩치 (Silver 5)
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int info[50][2];
	int ans[50];  // 인덱스번째 사람보다 덩치 큰 사람의 수 저장 = 덩치 등수
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i][0] >> info[i][1];
		ans[i] = 1;
	}

	for (int i = 0; i < n; i++) {  // i번째 사람의 덩치 등수 정하기
		for (int j = 0; j < n; j++) {
			if (info[i][0] < info[j][0] && info[i][1] < info[j][1])  // j번째 사람이 i번째 보다 덩치 크면 ans값 증가
				ans[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return 0;
}
