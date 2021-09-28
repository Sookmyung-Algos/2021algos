#include <iostream>
#define NUM 1000000003

using namespace std;
int N, K;
int color[1002][1002];

int solve() {
	color[1][1] = 1; // 1개의 색상환에서 1개를 선택하는 방법은 1가지
	for (int i = 2; i <= N; i++) {
		for (int j = 1; 2 * j <= i + 1; j++) {
			color[i][j] = color[i - 2][j - 1] + color[i - 1][j];
			/*
			우선 색상환을 일렬로 가정을 하고, 첫번째로 선택한 색이 마지막 색인 경우와 아닌 경우로 나누어서 구한다.
			마지막 색인 경우는 그 바로 앞의 색만 제외를 하고 생각을 해주면 되기 때문에 N-2개의 색상환에서 K-1개를 마저 선택해주면 되는 것이다.
			아닌 경우는 그 양옆의 색을 제외를 시켜야 한다. 그런데 마지막 색은 선택을 하지 않았기 때문에 없다고 생각을 해도 되므로 N-1개 중에서 K개를 선택하는 경우가 된다.
			그 두 가지 경우를 더한 값이 최종적으로 N개의 색상환에서 K개를 선택하는 경우의 수가 된다.
			*/
			color[i][j] %= NUM;
		}
	}
	return (color[N - 3][K - 1] + color[N - 1][K]) % NUM;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i <= N; i++) color[i][0] = 1;
	// N개의 색상환에서 0개를 선택하는 방법은 전부 1가지이다.

	cout << solve() << "\n";
	return 0;
}
