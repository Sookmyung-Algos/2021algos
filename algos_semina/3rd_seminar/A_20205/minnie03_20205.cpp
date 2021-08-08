#include <iostream>
using namespace std;

int main() {
	int n, k;
	int bit[11][11];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bit[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int line = 0;
		while (line<k) {
			for (int j = 0; j < n; j++) {
				for (int m = 0; m < k; m++)
					cout << bit[i][j]<<' ';
			}
			cout << endl;
			line++;
		}
	}
	return 0;
}
