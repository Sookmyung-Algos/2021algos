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
		while (line<k) { //k개의 줄 동안
			for (int j = 0; j < n; j++) { //n개의 숫자를
				for (int m = 0; m < k; m++) //각각 k번 
					cout << bit[i][j]<<' '; //출력
			}
			cout << endl;
			line++; //한 줄이 끝날 때마다 line++하여 몇번째 줄인지 체크
		}
	}
	return 0;
}
