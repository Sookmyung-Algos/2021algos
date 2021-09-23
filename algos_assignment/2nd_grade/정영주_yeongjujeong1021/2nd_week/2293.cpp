#include <iostream>
#define MAX 100001
using namespace std;

int main() {
	int n, k, arr[101], check[MAX] = { 0, };
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	check[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++)
			check[j] += check[j - arr[i]];
	}

	cout << check[k] << '\n';

	return 0;
}
