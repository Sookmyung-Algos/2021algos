#include <iostream>
#include <vector>

using namespace std;
int N;
vector<pair<int, int>> v;
int ring[101];

int gcd(int a, int b) // 최대 공약수 구해서 반환하는 함수
{
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve(int x, int y) { // 분수 구해서 벡터에 저장하는 함수
	if (x % y == 0) {
		x = x / y;
		y = 1;
	}
	else {
		int g = gcd(x, y);
		x = x / g;
		y = y / g;
	}
	v.push_back({ x, y });
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> ring[i];

	for (int i = 1; i < N; i++) {
		solve(ring[0], ring[i]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "/" << v[i].second << "\n";
	}

	return 0;
}
