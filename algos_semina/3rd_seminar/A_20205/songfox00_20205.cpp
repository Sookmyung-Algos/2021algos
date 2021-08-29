#include <iostream>
#include <vector>

using namespace std;

int arr[11][11];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < k; z++) {
			for (int j = 0; j < n; j++) {
				for (int zz = 0; zz < k; zz++) {
					cout << arr[i][j]<<' ';
				}
			}
			cout << "\n";
		}
	}

	return 0;
}
