#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	const int MAX = 10000;
	int K, N;
	long long cable[MAX];
	cin >> K >> N;

	long long low = 1, high = 0;
	for (int i = 0; i < K; i++) {
		cin >> cable[i];
		high = max(high, cable[i]);
	}

	int cnt = 0;
	long long result = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;

		for (int i = 0; i < K; i++)
			cnt += cable[i] / mid;

		if (cnt >= N) {
			result = max(result, mid);
			low = mid + 1;
		}
		else high = mid - 1;
		cnt = 0;
	}
	cout << result << "\n";
}
