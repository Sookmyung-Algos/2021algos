#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, word;
	bool check;
	int cnt = 0;
	getline(cin, s);
	getline(cin, word);

	if (s.size() < word.size()) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < s.size() - word.size() + 1; i++) {
		if (s[i] == word[0]) {// 다음 글자를 비교하여 단어가 맞는지 확인한다
			check = true;
			for (int j = 0; j < word.size(); j++) {
				if (s[i + j] != word[j]) {
					check = false;
					break;
				}
			}
			if (check == true) {
				cnt++;
				i = i + word.size() - 1;
			}		
			check = true;
		}
	}
	cout << cnt;
}
