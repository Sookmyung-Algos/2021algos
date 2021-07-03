#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<pair<int, int>> b;

	int n;  // 풍선 개수
	int move;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> move;
		b.push_back(make_pair(i, move));  // i는 풍선 번호
	}

	while (!b.empty()) {  // 풍선이 있을 동안
		cout << b.front().first << "\n";  // 제거된 풍선 번호
		int next = b.front().second;  // 움직일 거리
		b.erase(b.begin());  // 풍선 제거

		// 하나 제거한 후 v가 empty인 경우
		if (b.empty())
			return 0;

		// 이동할 거리가 양수이면
		if (next > 0) {
			for (int i = 0; i < next - 1; i++) {
				b.push_back(b.front());  // 원형임을 고려해 next만큼의 풍선들을 뒤로 옮김
				b.erase(b.begin());
			}
		}
		// 이동할 거리가 음수이면
		else {
			for (int i = 0; i < abs(next); i++) {  // 절댓값만큼 이동
				b.insert(b.begin(), b.back());  // 반대로
				b.erase(b.end() - 1);
			}
		}
	}
	return 0;
}
