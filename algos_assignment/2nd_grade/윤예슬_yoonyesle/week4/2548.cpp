#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, a[20001];
	cin >> n;
	for(i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	cout << a[(n - 1) / 2];
	return 0;
}
