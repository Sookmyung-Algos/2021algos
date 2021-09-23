#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair <int, string> x, pair <int, string> y) {  //커스텀 정렬 - 정렬함수 stable_sort의 세 번째 인자를 이용하기 위한 compare 함수를 선언
	return x.first < y.first;  //회원 x와 y의 우선순위를 반환
}

int main() {
	int N;  //온라인 저지 회원의 수를 입력받기 위한 정수형 변수 N 선언
	cin >> N;  //N을 입력받음
	pair <int, string> p;  //p라는 이름의 pair 생성(나이와 이름을 입력받기 위해 각각의 인자를 int와 string으로 지정)
	vector <pair<int, string>> v;  //pair를 인자로 갖는 vector v 생성

	for (int i = 0; i < N; i++) {  //N번 반복하는 for문
		cin >> p.first >> p.second;  //각 줄마다 pair(나이,이름)를 입력받음
		v.push_back(p);   //입력받은 pair를 순서대로 vector에 push 해줌
	}
	stable_sort(v.begin(), v.end(), compare);  //compare함수를 이용해 vector에 입력받은 회원들을 정렬

	for (int i = 0; i < N; i++) {   //정렬된 회원들을 출력하기 위해 N번 반복하는 for문
		cout << v[i].first << ' ' << v[i].second << '\n';  //예제 출력 형식에 맞게 회원들의 나이와 이름을 출력해주며 마무리
	}

	return 0;
}
