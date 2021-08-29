#include <iostream>
using namespace std;

int N;
int a[1000001];
int card[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	int num = N;
	int i1 = 0, i2 = 1, i3 = N - 1;
	for (int i = 0; i < N; i++) {
		if (a[i] == 1) {
			card[i1] = num;
			if (card[i1 + 1] == 0) i1++;
			else i1 = i2 + 1;
		}
		else if (a[i] == 2) {
			if (card[i1 + 1] == 0) i2 = i1 + 1;
			else i2 += 1;
			card[i2] = num;
		}
		else {
			card[i3] = num;
			i3--;
		}
		num--;
	}

	for (int i = 0; i < N; i++) cout << card[i] << ' ';

	return 0;
}
