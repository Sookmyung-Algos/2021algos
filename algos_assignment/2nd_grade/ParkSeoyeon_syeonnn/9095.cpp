// 9095 1,2,3 더하기

#include<iostream>

using namespace std;

int arr[11];

int main() {
	int n, t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n; 

		arr[1] = 1;	// 1
		arr[2] = 2;	// 1+1,2
		arr[3] = 4;	// 1+1+1, 1+2, 2+1, 3

		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}

		cout << arr[n] << '\n';
	}
	
	return 0;
}
