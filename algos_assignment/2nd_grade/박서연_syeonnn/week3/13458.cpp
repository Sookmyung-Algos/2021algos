#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, main, vice;
	long long cnt = 0; //전체 감독관의 수는 int 범위를 벗어날 수 있으므로 long long 사용함
	int num[1000001];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	cin >> main >> vice;

	for (int i = 0; i < N; i++) {
		cnt++;
		num[i] -= main;

		if (num[i] > 0) { // 응시자수가 0보다 클 경우, 감독관 1명 이상 필요함. num[i]가 main보다 클 필요없음
			if (num[i] % vice == 0)
				cnt += (num[i] / vice);
			else // 나머지 인원이 생기는 경우 부감독관 1명 더 필요함
				cnt += (num[i] / vice) + 1;
		}
	}
		
	cout << cnt;

	return 0;
}
