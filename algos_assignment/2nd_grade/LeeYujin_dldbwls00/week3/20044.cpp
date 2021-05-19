#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 팀원의 코딩 역량의 합이 최대한 일정하게 유지하려면
// 합이 최솟값이 최대한 크게 만들어야한다

int main() {
	int n; // 팀 수
	int w, ans = 200001; // 코딩 역량의 최댓값이 200000이므로 겹치지 않게 초기화
	vector<int> v; // 코딩 역량을 벡터에 넣어 정리
	
	cin >> n;
	for (int i = 0; i < 2 * n; i++) { // 학생의 코딩 역량을 나타내는 2n개의 양의 정수
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end()); // 오름차순 정렬

	// 최솟값 업데이트
	for (int i = 0; i < 2 * n; i++)	ans = min(ans, v[i] + v[2 * n - 1 - i]);
	cout << ans;

	return 0;
}
