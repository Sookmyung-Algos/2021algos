#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[11][11];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int t = 0; t < k; t++) {
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < k; z++) {
					cout << arr[i][j] << ' ';
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
