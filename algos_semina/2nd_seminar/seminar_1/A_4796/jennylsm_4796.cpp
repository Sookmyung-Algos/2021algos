#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int L, P, V;
	int num = 1;
	while (1) {
		int max = 0;
		cin >> L >> P >> V;
		if (L == 0) break;
		max += L;
		V -= P;
		while (V >= L) {
			max += L;
			V -= P;
			if (V < 0) break;
		}
		if (V > 0) max += V;
		cout << "Case " << num++ << ": " << max << "\n";
	}
	return 0;
}
