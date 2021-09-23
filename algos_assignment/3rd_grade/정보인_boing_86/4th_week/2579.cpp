#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;
int score[301] = { 0, };

int main() {
	int n, a;
	int x, y, ans;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	score[0] = v[0];
	score[1] = max(v[0] + v[1], v[1]);
	score[2] = max(v[0] + v[2], v[1] + v[2]);

	for (int i = 3; i < n; i++) {
		x = score[i - 2] + v[i];
		y = v[i] + v[i - 1] + score[i - 3];
		score[i] = max(x, y);
	}
	ans = score[n - 1]; //score에서 잘못된 데이터를 읽고 있습니다. 읽기가 가능한 크기는 '1204'인데 실제로는 '-4'바이트만 읽을 수 있습니다 뭐지?
	cout << ans;
}
