#include <iostream>
using namespace std;

int n, k;
int input;
int image[11][11];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> image[i][j];
	}

	for (int i = 0; i < n; i++) {  // 한 줄 선택
		for (int ki = 0; ki < k; ki++) {
			for (int j = 0; j < n; j++) {
				int bit = image[i][j];
				for (int kj = 0; kj < k; kj++)
					cout << bit << ' ';
			}
			cout << "\n";
		}
	}
	return 0;
}
