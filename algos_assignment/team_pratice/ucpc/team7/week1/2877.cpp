#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {

	int k, two = 1, count = 1, result = 0;
	cin >> k;

	while (true) {
		if (k - 2 * two > 0) {// k는 자릿수 순번
			two = two * 2;
			k = k - two;
			count++;// 전체 자릿수
		}
		else
			break;
	}
	k = k - 1;

	string s = "";
	while (k > 0) {
		if (k % 2 == 1)
			s = "1" + s;
		else
			s = "0" + s;
		k = k / 2;
	}

	int len = s.length();
	if (count > len) {
		for (int i = 0; i < count - len; i++) {
			cout << '4';
		}
	}
	for (int i = 0; i < len; i++) {
		if (s[i] == '0')
			cout << '4';
		else if (s[i] == '1')
			cout << '7';
	}
	cout << '\n';
}
