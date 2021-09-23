#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, float> m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //시간을 줄이기 위해 넣어준다
	string str;  //문자열 선언
	float c = 0;  

	while (getline(cin, str)) {  //문자열 입력
		c++;
		if (m.find(str) != m.end()) {  
			m[str] += 1;   //해당하는 값에 1씩 더해준다.
		}
		else
			m[str] = 1;  //아닌경우 1을 저장한다.
	}
	cout << fixed;
	cout.precision(4);  //소수 넷째자리까지 출력한다.
	for (auto a = m.begin(); a != m.end(); a++) {
		float v = (a->second / c) * 100; //백분율을 측정한다.
		cout << a->first << " ";
		cout << v << endl;
	}
	return 0;
}
