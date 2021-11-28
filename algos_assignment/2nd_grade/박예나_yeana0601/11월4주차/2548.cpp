#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int num[20001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	sort(num, num + n);
	cout << num[(n - 1) / 2];
}
