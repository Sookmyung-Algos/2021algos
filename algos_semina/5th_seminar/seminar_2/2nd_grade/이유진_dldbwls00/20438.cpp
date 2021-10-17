#include <iostream>
using namespace std;

bool check[5003] = { false, };
int arr[5003] = { 0, }; //출석코드를 받은 학생 1로 표시

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, q, m;
	cin >> n >> k >> q >> m;

	while (k--) { //조는 학생
		int temp;
		cin >> temp;
		check[temp] = true;
	}
	while (q--) {
		int temp;
		cin >> temp;
		int x = 1; // 배수 계산을 위한 변수
		if (!check[temp]) {//졸지 않은 학생에 대해
			while (temp * x <= n + 2) {
				if (!check[temp * x])	arr[temp * x] = 1;
				x++;
			}
		}
	}

	//누적합 : 시간 초과 해결
	int sum[5003] = { 0, }; //i번째 학생가지 출석체크를 한 인원의 수
	for (int i = 3; i <= n + 2; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	while(m--) {// 구간
		int s, e;
		cin >> s >> e;
		cout << (e - s + 1) - (sum[e] - sum[s - 1]) << "\n"; //구간의 인원수-누적합
	}
	return 0;
}
