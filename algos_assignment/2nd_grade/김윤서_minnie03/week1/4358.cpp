#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> m;
	string tree;
	float count = 0;

	while (getline(cin, tree)) {
		
		if (m.find(tree) !=m.end()) {//입력받은 tree 값의 value가 있다면 
			m[tree]++; //value++
		}
		else {//없다면 새로 tree를 만들어주고 value=1
			m[tree] = 1; 
		}
		count++;
	}

	cout << fixed; //소수점을 고정시켜 표현
	cout.precision(4); //4자리까지 표현(반올림)

	for (auto it = m.begin(); it != m.end(); it++) {//auto 키워드는 선언된 변수의 초깃값을 활용하여 해당 형식 추론
		float per = (it->second / count) * 100;
		cout << (it->first) << " " << per << '\n';
	}
	
	return 0;
}
