#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 사용

using namespace std;

void init() { // 시간 초과 방지
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

// 벡터 사용
int main() {

	int num; // 입력할 좌표 개수
	cin >> num;

	vector<pair<int, int>> vec(num); // 벡터 생성

	for (int i = 0; i < num; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end()); // sort 사용


	for (int i = 0; i < num; i++) {
		cout << vec[i].first << " " << vec[i].second << '\n'; // 시간 초과 방지
	}
	return 0;
}
