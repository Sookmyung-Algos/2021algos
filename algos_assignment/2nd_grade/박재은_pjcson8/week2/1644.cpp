#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> v(n + 1, 1); //0~n 소수인지 판별

	//에라토스테네스의 체 알고리즘
	for (int i = 2; i * i <= n; i++) {
		if (v[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i) {
			v[j] = 0; //j는 i의 배수 -> 소수 x
		}
	}

	vector<int> prime;

	for (int i = 2; i <= n; i++) {
		if (v[i])
			prime.push_back(i);		//v[i]가 1(소수)이면 prime 벡터에 추가
	}
	int s = 0, e = 0; //s = start , e=end
	int sum = 0;
	int ans = 0;

	//투 포인터 알고리즘
	while (1) {
		if (sum > n) {		
			sum -= prime[s];	//s에서 가장 앞쪽 prime값 빼기.
			s++;
		}
		else if (sum < n) {
			if (e >= prime.size()) //e가 prime 벡터의 크기와 같거나 크면 중지
				break;
			sum += prime[e]; // 그렇지 않으면 sum 에 다음 prime값 더하기.
			e++;
		}
		else {	//sum == n인 경우
			ans++;	//문제의 조건을 만족시키는 경우이므로 ans 1증가.
			if (e >= prime.size())
				break;
			sum += prime[e];
			e++;
		}
	}
	cout << ans;

	return 0;
}
