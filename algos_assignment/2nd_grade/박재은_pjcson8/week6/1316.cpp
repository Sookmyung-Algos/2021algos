#include <iostream>
#include <string>

using namespace std;

bool wordCheck(string str) {
	bool alpa[26] = { false };

	for (int i = 0; i < str.length(); i++) {
		if (alpa[str[i] - 'a'])
			return false;
		else {
			char tmp = str[i];
			alpa[str[i] - 'a'] = true;

			while (1) {
				if (tmp != str[++i]) {
					i--;
					break;
				}
			}
		}		
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		
		if (wordCheck(tmp)) {
			count++;
		}
	}
	cout << count << '\n';

	return 0;
}
