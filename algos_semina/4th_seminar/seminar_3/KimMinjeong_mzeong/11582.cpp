#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int k;
	cin >> k;

	for (int n = 0, i = 2; ; i *= 2) {
		n = 0;
		while (1) {
			sort(arr + n, arr + (n + i));
			n += i;
			if (n == N) break;
		}
		if (k == N / i) break;
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}
