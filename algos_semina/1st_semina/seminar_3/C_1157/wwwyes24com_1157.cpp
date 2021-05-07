#include <iostream>
using namespace std;

int main() {
	string s;
	char c;
	bool over = 0; 
	int max = 0;
	int alp[30] = { 0, };
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			alp[s[i] - 'a']++;
		else if ('A' <= s[i] && s[i] <= 'Z')
			alp[s[i] - 'A']++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (alp[i] == 0)
			continue;
		if (alp[max] < alp[i] && over == 0) { 
			max = i;
			
		}
		else if (alp[max] == alp[i] && i!=0) {
			over = 1; 
		}
			
		else if (alp[max] < alp[i] && over == 1) {
			over = 0;
			max = i;
			
		}
		
	}
	if (over == 1) {
		cout << '?';
		return 0;
	}
	c = 'A' + max;
	cout << c;
}
