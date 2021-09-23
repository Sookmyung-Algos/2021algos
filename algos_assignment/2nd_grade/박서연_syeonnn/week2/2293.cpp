#include <iostream>
using namespace std;

int n, k;
int coin[101];
int num[10001];

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coin[i]; // coin 배열에 주어진 동전의 가치 저장

	num[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			num[j] += num[j - coin[i]];
		} // j원을 만드는 방법을 구하기 위해서는 ( j-coin[i] )원이 있어야 하므로 해당 금액을 만드는 방법의 수를 더해준다.
	}
	cout << num[k];

	return 0;
}
