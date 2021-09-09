#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 100) {
		cout << n;
	}
	else {
		int cnt = 99;
		int tmp = 111;
		while (tmp <= n) {
			int n1 = tmp % 10;
			int n2 = tmp / 10 % 10;
			int n3 = tmp / 100;
			if (n3 - n2 == n2 - n1) {
				cnt++;
			}
			tmp++;
		}
		cout << cnt;
	}
}
