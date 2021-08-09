#include <iostream>
using namespace std;

int map[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < k; m++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < k; l++) {
					cout << map[i][j] << " ";
				}
			}
			cout << "\n";
		}
	}
}
