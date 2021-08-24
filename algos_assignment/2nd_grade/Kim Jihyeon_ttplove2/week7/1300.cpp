#include <iostream>
using namespace std;

int N, K;
int result = 0;

// mid값보다 작은 수의 개수를 구해서 mid의 인덱스를 알아내는 함수
int find_idx(int key)
{
	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		cnt += min(key / i, N);
		// i는 행의 번호를 가리킴.
		// i로 key를 나눈 몫은 해당 행에서 key값보다 작은 값의 개수임.
		// i가 1이거나, N의 값이 커지면 key / i가 N보다 커지는 경우도 발생하므로 둘 중에 작은 값을 저장하도록 한다.
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	// 이분 탐색
	// 일반 정렬을 이용하여 구하면 시간 초과가 발생한다.
	int s = 1;
	int e = K;
	// e가 N * N이 아니라 K인 이유는 결과값은 K보다 작거나 같기 때문이다.
	while (s <= e) {
		int m = (s + e) / 2;
		if (find_idx(m) >= K) {
			// m값의 인덱스가 K보다 크거나 같은 경우
			result = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	cout << result << "\n";
	return 0;
}
