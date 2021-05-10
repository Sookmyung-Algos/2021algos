/////////////////////////////////////////////
//작성날짜: 2021.04.07
//문제: 백준 4358)생태학
//기타: map 사용 예제
/////////////////////////////////////////////

#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {

	//fast I/O
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	//(key=string, value=int) 타입의 map만들기
	map <string,int> m;
	string tree; // 변수 선언
	float count = 0; //변수 선언 및 초기화

	while (getline(cin, tree)) { //나무 이름 입력
		if (m.find(tree) != m.end()) { //iterator
			m[tree] += 1;
		}
		else {
			m[tree] = 1;
		}
		count++;
	}

	cout << fixed;
	cout.precision(4); //소수점 4번째까지

	//백분율 계산
	for (auto it = m.begin(); it != m.end(); it++) { //iterator
		float per = (it->second / count) * 100;
		cout << (it->first) << ' ' << per << '\n';
	}
	return 0;
}
