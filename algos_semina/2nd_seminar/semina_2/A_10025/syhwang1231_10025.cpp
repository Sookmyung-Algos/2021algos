#include <iostream>
#define MAX 1000001

using namespace std;

int ice[MAX];

int main(void) {
	int n, k, g, x;  // n은 얼음 양동이 개수, k는 움직일 수 있는 최대 거리
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> g >> x;
		ice[x] = g;  // 좌표 x에 얼음 g개
	}

	k = 2 * k + 1;  // 구해야하는 얼음 총합의 좌표 길이

	//int s = 0, e = k - 1;  // 투포인터
	int currSum = 0;  // 합은 0으로 초기화
	int sum = 0;

	for (int i = 0; i < MAX; i++) {
		if (i >= k)  // 유효한 경우
			sum -= ice[i - k];
		sum += ice[i];
		if (sum > currSum)
			currSum = sum;
	}

	cout << currSum;
	return 0;
}
