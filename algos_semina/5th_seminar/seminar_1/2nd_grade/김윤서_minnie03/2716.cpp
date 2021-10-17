#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; // 테스트 케이스 개수
	cin >> t;
	char c; // 남은 공백 제거
	c = cin.get();

	while(t--) {
		string s;
		getline(cin, s); // 한 줄 입력

		int level = 0, maxlevel = 0;
		for (int i = 0; i < s.length(); i++) { // 괄호개수만큼
			if (s[i] == '[') { // 만약 열린 괄호라면 
				level++; // level 1 증가
				if (level > maxlevel) // 최대 level값 구하여 maxlevel에 저장
					maxlevel = level;
			}
			else level--;
		}
		int result = 1;
		for (int i = 0; i < maxlevel; i++)
			result *= 2; // 괄호의 개수에 비례하여 2배씩 곱함
		cout << result << endl;
	}
	return 0;
}
