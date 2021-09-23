#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n, arr[10], i = 0;
	cin >> n;

	do {
		arr[i++] = n % 10;
		n = n / 10;
	} while (n > 0);

	sort(arr, arr+i, greater<int>());

	for (int j = 0; j < i; j++)
		cout << arr[j];
}
