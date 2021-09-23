#include <iostream>
#include <cstring>
using namespace std;
int tile[1010];
int dp(int n) {
	if (tile[n] != -1)
		return tile[n];

	else
		return tile[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main() {
	int n;
	cin >> n;
	memset(tile + 1, -1, n * sizeof(int));
	tile[1] = 1, tile[2] = 2;

	cout << dp(n);
}
