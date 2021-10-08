#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l, c; 
char pw[16];

void password(int pos, string str, int ja, int mo) {
	if (str.size() == l) { // str이 암호길이인 경우
		if (ja < 2 || mo < 1) return; // 자음과 모음이 조건을 충족하지 못하면 종료

		cout << str << endl; // 조건을 충족한다면 그대로 출력
	}
	for (int i = pos; i < c; i++) {
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
			password(i + 1, str + pw[i], ja, mo + 1);
		else
			password(i + 1, str + pw[i], ja + 1, mo);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) { // 문자 입력
		cin >> pw[i];
	}
	sort(pw, pw + c); // 알파벳 순서대로 정렬
	password(0, "", 0, 0);
	return 0;
}
