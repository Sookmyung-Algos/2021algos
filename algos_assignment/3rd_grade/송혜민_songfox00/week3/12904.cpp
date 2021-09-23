#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	while (t.length() > s.length()) { //t에서 알파벳을 삭제하면서 s랑 같아지는 지 확인
		if (t.back() == 'A')  //t 끝 글자가 A일 때
			t.pop_back(); //A 삭제
		else {  //'B'이면
			t.pop_back();  //B 삭제
			reverse(t.begin(), t.end()); //뒤집기
		}
	}
	if (t == s)
		cout << 1;
	else
		cout << 0;

	return 0;
}
