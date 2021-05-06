#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool desc(int a, int b) {
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count[26] = { 0, };
	string str;
	int a, ans;
	int max = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		a = str.at(i);

		if (a > 64 && a < 91) {
			count[a - 65]++;
		}

		if (a > 96 && a < 123) {
			count[a - 97]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			ans = i + 65;
		}
	}

	sort(count, count+26);

	if (count[25] == count[24]) {
		cout << "?";
	}

	else
		cout << (char)ans;
}
