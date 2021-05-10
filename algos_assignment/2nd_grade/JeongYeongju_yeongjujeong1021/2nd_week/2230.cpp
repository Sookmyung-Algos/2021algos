#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
#define MAX_GAP 2000000000

int arr[MAX];

bool f(int a, int b) {
	return a > b;
}

int main() {
	int n, m, l = 0, r = 0, gap = 0, min = MAX_GAP;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n, f);

	while (1) {
		if (r == n) break;
		gap = arr[l] - arr[r];
		if (gap >= m) {
			if (gap < min)
				min = gap;
			l++;
		}
		else r++;
	}
	cout << min << '\n';

	return 0;
}
