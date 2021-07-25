#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	B += B.substr(0);
	int pi[100001] = {0}, n = A.length();
	for (int i = 1, j = 0; i < n; ++i) {
		while (j && A[i] != A[j])
			j = pi[j - 1];
		if (A[i] == A[j])
			pi[i] = ++j;
	}
	int cnt = 0;
	for (int i = 0, j = 0; i < 2 * n - 1; ++i) {
		while (j && B[i] != A[j])
			j = pi[j - 1];
		if (B[i] == A[j]) {
			if (j == n - 1) {
				++cnt;
				j = pi[j];
			}
			else
				++j;
		}
	}
	printf("%d", cnt);
	return 0;
}
