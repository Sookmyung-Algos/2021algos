#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<char> v; // 실제 char을 넣을 벡터
	vector<int> choose; 
	
	int l, c;
	cin >> l >> c;

	// 문자 입력
	for (int i = 0; i < c; i++) {
		char x;
		cin >> x;
		v.push_back(x);
		choose.push_back(1);
	}
	sort(v.begin(), v.end()); //정렬

	//뽑으려는 문자 개수에 맞게 pick을 바꿔주자.
	//pick을 0 0 0 0 1 1 로 만들어서 pick에서 0을 가진 위치에 해당되는 4개의 v[i]를 뽑을 것이다.
	for (int i = 0; i < l; i++) {
		choose[i] = 0;
	}

	do {
		string s = "";
		for (int i = 0; i < c; i++) {
			if (choose[i] == 0) {
				s = s + v[i]; //뽑은 문자 조합을 string으로 받기
			}
		}

		int cnt1 = 0;//모음 개수
		int cnt2 = 0;//자음 개수
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') // 모음
				cnt1++;
			else // 자음
				cnt2++;
		}
		if (cnt1 < 1 || cnt2 < 2) // 조건 따지기
			continue; // 출력 안함
		cout << s << '\n';
	} while (next_permutation(choose.begin(), choose.end()));

}
