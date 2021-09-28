#include <iostream>

using namespace std;
long long N;
long long result;

long long find_result(long long s, long long k, long long n) {// 판별식 : t = (s - k) / 2
	while (true) {
		long long t = (s - k) / 2;
		if (t < n && n <= t + k) {
			n = n - t;
			break;
		}
		else if (t + k < n) {
			n -= (t + k);
			k--;
			s = t;
		}
		else if (t >= n) {
			k--;
			s = t;
		}
	}
	return n;
}

void solve()
{
	long long s = 3, k = 4;
	// s : 전체 문자열 길이 | k : 중간 문자열 길이

	while (s < N) {
		s = 2 * s + k; // n보다 커질 때까지 전체 문자열의 길이를 증가시킴
		k++; // s(x)에서 x의 크기가 1 늘어날 수록 중간 문자열의 길이가 1늘어남
	}
	k--; // 마지막 반복에서 s가 n보다 커졌지만 k값도 한 번 더 증가시켜줬으므로 1을 빼준다.
	result = find_result(s, k, N);

	if (result == 1) cout << "m\n";
	else cout << "o\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solve();
	return 0;
}
