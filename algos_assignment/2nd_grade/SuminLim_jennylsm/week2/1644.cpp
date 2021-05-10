#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> v(n + 1, 1);

	for (int i = 2; i * i <= n; i++) {
		if (v[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			v[j] = 0;
		}
	}
	vector<int> prime;

	for (int i = 2; i <= n; i++) {
		if (v[i]) prime.push_back(i);
	}
	int p = 0, q = 0;  //소수값을 참조할 인덱스
	int sum = 0;  //소수의합
	int result = 0;
	while (1) {
		if (sum > n) {  //sum이 n보다 크면 p번째 소수값을 빼고 p값 증가
			sum -= prime[p];
			p++;
		}
		else if (sum < n) {   //sum이 n보다 작으면 q번째 소수값 더하고 q값 증다
			if (q >= prime.size()) break;
			sum += prime[q];
			q++;
		}
		else {  //sum이 n과 같으면 결과값에 1증가
			result++;
			if (q >= prime.size()) break;
			sum += prime[q];
			q++;
		}
	}
	cout << result;

	return 0;
