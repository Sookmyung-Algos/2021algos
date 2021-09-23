#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;//전체 나무 수
map<string, int> tree;//map에 나무 이름과 개수 저장
string name;//map의 key

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);//입출력 시간 단축

	double total = 0;

	while (getline(cin, name)) {
		N += 1;
		tree[name]++;
	}//나무 이름을 입력받으며 해당 나무의 개수와 전체 나무의 개수 세기

	cout << fixed;
	cout.precision(4);//소숫점 4째 자리까지 반올림해 출력

	for (auto i = tree.begin(); i != tree.end(); i++) {
		string tree_name = i->first;//map의 key 저장
		double n = i->second;//map의 value 저장
		n /= N;
		n *= 100.0;//하나의 종이 차지하는 비율을 백분율로 표현
		cout << tree_name << ' ' << n << '\n';
	}
	return 0;
}
