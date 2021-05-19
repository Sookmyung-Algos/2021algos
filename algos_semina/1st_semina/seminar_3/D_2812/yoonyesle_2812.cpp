#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, top = -1;
	char stack[500001];
	string s;
	cin >> n >> k >> s;
	int K = k;
	for (int i = 0; i < n; ++i) {
		while (k && top >= 0 && stack[top] < s[i]) {
			--top;
			--k;
		}
		stack[++top] = s[i];
	}
	for (int i = 0; i < n - K; ++i) {
		cout << stack[i];
	}
	return 0;
}
