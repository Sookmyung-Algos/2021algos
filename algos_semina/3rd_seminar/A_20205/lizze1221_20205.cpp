#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[11][11];
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int m = 0; m < n; m++) {
				for (int l = 0; l < k; l++) {
					cout << arr[i][m]<<" ";				
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
