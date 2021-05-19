#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;

	cin >> n;
	while (n > 0) {
		if (n % 5 == 0) {
			cnt++;
			n -= 5;
		}
		else {
			cnt++;
			n -= 3;
		}
	}
	if (n == 0)
		cout << cnt;
	else
		cout << -1;
}
