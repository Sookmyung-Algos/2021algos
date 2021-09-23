#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int score[1000001] = { 0, };

int main() {
	int n;
	int b, c;

	cin >> n;

	for (int i = 2; i < n+1; i++) {

		score[i] = score[i - 1] + 1;

		if (i % 3 == 0) {
			b = score[i / 3] + 1;
			score[i] = min(score[i], b);
		}

		if (i % 2 == 0) {
			c = score[i / 2] + 1;
			score[i] = min(score[i], c);
		}
	}
	cout << score[n];
}
