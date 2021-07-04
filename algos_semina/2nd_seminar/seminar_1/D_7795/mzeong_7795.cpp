#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[20001];
int b[20001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int T, N, M;
	cin >> T;

	while (T--) {
		int ans = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		cin >> N >> M;

		for (int i = 0; i < N; i++)
			cin >> a[i];
		for (int i = 0; i < M; i++)
			cin >> b[i];

		sort(a, a+N, cmp);
		sort(b, b+M, cmp);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (a[i] > b[j]) {
					ans += (M - j);
					break;
				}
		cout << ans << "\n";
	}
}
