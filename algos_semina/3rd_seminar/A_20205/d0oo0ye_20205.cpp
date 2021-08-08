#include <iostream>
using namespace std;

int main()
{
	int n, k;
	int p[10][10];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int a = 0; a < k; a++) {
			for (int j = 0; j < n; j++) {
				for (int b = 0; b < k; b++) {
					cout << p[i][j];
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
