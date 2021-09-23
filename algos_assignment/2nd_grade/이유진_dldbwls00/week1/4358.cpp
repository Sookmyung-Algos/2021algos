
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
	map<string, int> m; //<나무이름, 불린 횟수>
	float percent, cnt = 0; //나무의 비율, 전체 나무 개수
	string tree;

	while (getline(cin, tree)) { //나무이름 입력받음
		if (m.find(tree) != m.end())	m[tree]++; //이미 tree가 있는 경우
		else	m[tree] = 1;
		cnt++;
	}
	cout << fixed; //소수점 자리수 조절(고정)
	cout.precision(4); //소숫점아래 넷째자리까지

	for (auto iter = m.begin(); iter != m.end(); iter++) { //auto를 사용함으로 인해 map<string,int>::iterator iter;
		percent = (iter->second / cnt) * 100; //비율
		cout << (iter->first) << " " << percent << '\n';
	}
	return 0;
}
