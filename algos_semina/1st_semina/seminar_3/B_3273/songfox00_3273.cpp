#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;

	sort(arr, arr + n);

	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] + arr[j] == x)
				res++;
			else if (arr[i] + arr[j] > x)
				break;
		}
	}
	cout << res;
	return 0;
}
