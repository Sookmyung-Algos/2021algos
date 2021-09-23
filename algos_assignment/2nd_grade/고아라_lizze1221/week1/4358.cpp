#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map < string, int > map;
	string str;
	float total = 0;

	while (getline(cin, str)) {
		if (map.find(str) == map.end()) { 
			map[str] = 1;
		} 
		else {
			map[str] += 1;
		} // 동일한 str이 있으면 1 더해주기

		total++; // 전체 개수 
	}

	cout << fixed;
	cout.precision(4);
	// 소수점 넷째자리까지 반올림하여 표현하는 방법

	for (auto it = map.begin(); it != map.end(); it++) {
		float per = (it->second / total) * 100;
		cout << (it->first) << ' ' << per << '\n';
	} // 비율을 per 변수에 대입하고 출력해주기

	return 0;
}
