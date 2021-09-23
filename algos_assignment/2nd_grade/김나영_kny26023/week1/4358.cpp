#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m; //map m을 만들어준다
	string tree;
	float cnt = 0;  //개수를 받을 변수 cnt를 만들어준다
	while (getline(cin, tree)) {  //입력을 받을 때
		if (m.find(tree) != m.end()) {  //tree가 m에 이미 있으면
			m[tree] += 1; //m[tree]에 1을 더해준다
		}
		else {  //tree가 m에 없으면
			m[tree] = 1;  //m[tree]를 만들어주고 1을 넣어준다
		}
		cnt++;  //개수는 항상 더해준다
	}

	for (auto it = m.begin(); it != m.end(); it++) {  //iterator를 사용한다
		float portion = (it->second / cnt) * 100; //portion은 비율을 의미한다
		printf("%s %.4f\n", it->first.c_str(), portion);  //printf로 소수점 4번째 자리까지 print 해준다
	}
	return 0;
}
