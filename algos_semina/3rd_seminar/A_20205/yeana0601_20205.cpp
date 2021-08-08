#include <iostream>
#include <vector>
using namespace std;

int arr[11][11];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int b = 0; b < k; b++) {
			for (int j = 0; j < n; j++) {
				for (int a = 0; a < k; a++)
					cout << arr[i][j]<<" ";
			}
			cout << "\n";
		}
	}
	
	return 0;

}
