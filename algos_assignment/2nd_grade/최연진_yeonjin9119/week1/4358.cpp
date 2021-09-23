#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int>m;
int main() {
	//FAST I/O
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	string tree;
	float cnt = 0;
	while (getline(cin, tree)) {//한줄씩 입력받아 저장하기
		if (m.find(tree) != m.end()) {//만약 입력받은 TREE값이 MAP에 존재하지 않으면 m.find가 m.end를 반환할 것이므로 이를 이용
			m[tree] += 1;
		}
		else {
			m[tree] = 1;//tree가 처음 받는 단어라면 처음 받았다고 1을 저장해줌
		}
		cnt++;//전체 개수를 cnt에 저장
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++) {
		float per = (it->second / cnt) * 100;
		cout << (it->first) << " " << per << "\n";
	}
	return 0;
}
