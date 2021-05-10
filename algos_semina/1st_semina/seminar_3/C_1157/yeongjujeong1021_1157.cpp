#include <iostream>
#include <string>
#define MAX 100001
using namespace std;

int main() {
	int alpha[26] = { 0, }, len, max = 0, max_index, dupl = 0;
	char ans;
	string str;
	cin >> str;

	len = str.length();
	for (int i = 0; i < len; i++) {
		if ('a' <= str[i] && str[i] <= 'z')
			alpha[str[i] - 'a']++;
		else if ('A' <= str[i] && str[i] <= 'Z')
			alpha[str[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (max == alpha[i]) dupl = 1;
		else if (max < alpha[i]) {
			dupl = 0;
			max = alpha[i];
			max_index = i;
		}
	}

	if (dupl) cout << '?' << '\n';
	else {
		ans = 'A' + max_index;
		cout << ans << '\n';
	}

	return 0;
}
