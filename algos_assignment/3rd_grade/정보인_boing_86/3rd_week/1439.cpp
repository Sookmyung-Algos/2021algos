#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string s;
	int count = 0;

	cin >> s;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			count++;
		}
	}

	if (count % 2 == 0) {
		cout << count / 2;
	}
	else
		cout << count / 2 + 1;
}
