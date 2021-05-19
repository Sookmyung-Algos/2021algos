#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	while (1) {
		if (n % 5 == 0) {
			cnt += n / 5;
			cout << cnt;
			break;
		}
			n -= 3;
			cnt++;
			if (n < 0) {
				cout << -1;
				break;
			}
	}
}
