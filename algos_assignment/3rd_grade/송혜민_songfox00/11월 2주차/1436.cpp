#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, cnt = 0, res = 0;
	int temp;

	cin >> n;

	while (cnt != n) {
		res++;
		temp = res;
		while (temp != 0)
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				temp /= 10;
			}
	}
	cout << res;
}