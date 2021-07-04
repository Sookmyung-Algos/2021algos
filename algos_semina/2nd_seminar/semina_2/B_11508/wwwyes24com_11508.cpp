#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, sum = 0;
	int c[100010];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	
	sort(c, c + n, greater<>());
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2)
			sum += c[i];
	}
	cout << sum;

}
