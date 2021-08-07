// baekjoon 20207 달력
#include <iostream>
#include <cmath>
#define MAX 367
using namespace std;

int cal[MAX] = { 0, };  // 하루의 일정 수 저장
int n; // n: 일정의 개수(1<= n<= 1000)
int s, e;  // s: 시작 날짜, e: 종료 날짜

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		for (int j = s; j <= e; j++) {
			cal[j]++;
		}
	}

	int height = 0;
	int width = 0;
	int size = 0;
	for (int i = 1; i < MAX; i++) {
		if (cal[i] == 0) {  // i날에 일정이 없는 경우
			size += (width * height);
			width = height = 0;  // 코팅지 크기 초기화(새로운 코팅지)
			continue;
		}
		// 일정이 있는 경우
		width++;
		height = max(height, cal[i]);
	}
	cout << size;
	return 0;
}
