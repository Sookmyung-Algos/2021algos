#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int N; long long M, tree[MAX];

bool possible(long long height) {
	long long len = 0;

	for (int i = 0; i < N; i++)
		if (tree[i] - height > 0)
			len += tree[i] - height;
	
	if (len >= M) 
		return true;

	return false;
}

int main() {
	cin >> N >> M;

	long long low = 1, high = 0;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		high = max(high, tree[i]);
	}
	
	long long result = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (possible(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result << "\n";

	return 0;
}
