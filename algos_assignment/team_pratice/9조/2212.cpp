//baekjoon 2212 센서

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> sensor;
	vector<int> gap;

	int n, k;  // n: 센서의 개수, k: 집중국의 개수
	int s;

	cin >> n;
	cin >> k;

	gap.resize(n - 1);

	for (int i = 0; i < n; i++) {
		cin >> s;
		sensor.push_back(s);
	}
	sort(sensor.begin(), sensor.end());  // 센서의 위치 오름차순 정렬

	for (int i = 0; i < n - 1; i++) {
		gap[i] = sensor[i + 1] - sensor[i];
	}
	sort(gap.begin(), gap.end());  // 센서들 사이 거리 오름차순 정렬

	int sum = 0;
	for (int i = 0; i < n - k; i++) {  // k = 1 이면 gap 전부, k = 2이면 gap에서 제일 큰거 1개 제외 ...
		sum += gap[i];
	}

	cout << sum;
	return 0;
}
