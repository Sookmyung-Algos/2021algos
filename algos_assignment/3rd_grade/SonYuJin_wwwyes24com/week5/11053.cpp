#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, big = 0;
	int a[1010];
	int res[1010];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		res[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])
				res[i] = max(res[i], res[j] + 1);
		}
	}
	for (int i = 1; i <= n; i++) 
		big = max(big, res[i]);
	
	cout << big << " ";
}
