#include <iostream>
#include <map>
#include <string>
using namespace std;
map <string, double> trees;

int main() {
	ios_base::sync_with_stdio(false);       //연결 끊어주기-Fast I/O
	cin.tie(0); cout.tie(0);     

	string s;
	double cnt = 0;
	
	while (getline(cin, s)) {              //나무이름 받음
		if (m.find(s) != m.end())          //이미 동일한 나무(key)가 입력되어 있는 경우엔 value값 +1
			m[s] += 1;
		else                               //처음이면 value는 1
			m[s] = 1;
		cnt++;                             //중복 상관없이 나무 받을때마다 1씩 증가
	}
	cout << fixed;                        //소수점을 고정시킴(이게 없으면 실수 전체로 4째자리 표현)
	cout.precision(4);                    //소수점 4째자리까지 표현

	for (auto it = m.begin(); it != m.end(); it++) {    //맵에 있는 첫번째 원소부터 마지막 원소까지 반복
		double per = (it->second / cnt) * 100;        
		cout << (it->first) << " " << per << '\n';       //각 나무와 나무의 퍼센트 출력
	}
}
