#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int alp[26] = { 0, };
		int flag = 0;
		for (int j = 0; j < str.length(); j++) { // 알파벳 확인
			alp[str[j] - 'a']++;
			if (alp[str[j] - 'a'] > 1 && j > 0 && str[j] != str[j - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) 
			cnt++;
	}
	cout << cnt << endl;

	return 0;
}
