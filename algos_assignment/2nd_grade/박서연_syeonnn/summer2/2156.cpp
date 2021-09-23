// 2156 포도주 시식

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long wine[10001];
long long drink[10000001];

int main() {
	int n, w;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	drink[1] = wine[1];
	if (n > 1) {
		drink[2] = wine[1] + wine[2];
	}
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			drink[i] = max({ drink[i - 1], drink[i - 2] + wine[i], drink[i - 3] + wine[i - 1] + wine[i] });
		}    // max 함수에서 인수3개를 비교하기 위해서는 {} 필요함
			// 이번 차례에 마시지 않았을 때, 이번에 마시고 직전에 마시지 않았을 때, 이번과 직전에 마시고 그 전에 마시지 않았을 때
	}

	cout << drink[n];

	return 0;
}
