#include<iostream> //cin, cout 사용
#include<map> //map 헤더
#include<string> //getline사용
using namespace std; //식별자가 고유하도록 보장

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false); 
} //입출력 속도 개선

int main(void) {
	map<string, int> m; //string형 key와 int형 value를 갖는 맵 m 생성
	string name; //나무 이름
	float count = 0; //총 나무개수를 세는 변수 나중에 실수연산을 위해 float로

	while (getline(cin, name)) {//그냥 cin으로 받으면 공백에서 끊기므로 getline()으로 받습니다
		if (m.find(name) != m.end()) {//m.find()는 값이 없을때 m.end()를 반환하므로 이를 이용해 유무를 판단할 수 있습니다.
			m[name] += 1;
		}
		else {
			m[name] = 1;//m[]을 이용하여 값을 추가, 수정할 수 있습니다.
		}
		count++;//총 나무개수를 업데이트합니다.
	}
	cout << fixed; //소수점을 고정하겠다는 의미입니다.
	cout.precision(4); //소수점 4자리까지 출력한다는 의미입니다.

	for (auto it = m.begin(); it != m.end(); it++) {//반복자를 이용하여 순회합니다. map형은 key값의 오름차순으로 자동 정렬되어 저장되므로 따로 sort하지 않아도 됩니다.
		float per = (it->second / count) * 100;//백분율을 계산합니다
		cout << (it->first) << ' ' << per << '\n';//출력조건에 맞춰 출력합니다
	}
	return 0;
}
