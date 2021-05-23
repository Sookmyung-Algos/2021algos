#include <iostream>

using namespace std;

int arr[1001];

void insertion(int arr[], int n) {
	int i, j, next;
	for (i = 1; i < n; i++) {
		next = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (next < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = next;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	insertion(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}
