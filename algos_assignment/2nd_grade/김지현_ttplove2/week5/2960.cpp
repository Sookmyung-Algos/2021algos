#include <iostream>
#define MAXN 1001
using namespace std;

int N, K;

int solve()
{
	int cnt = K;
	bool arr[MAXN] = { 0, };

	for (int i = 2; i < N + 1; i++) {
		for (int j = i; j < N + 1; j+=i) {
			if (!arr[j]) {
				arr[j] = true;
				cnt--;
			}
			if (cnt == 0) {
				return j;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	cout << solve() << "\n";
	return 0;
}
