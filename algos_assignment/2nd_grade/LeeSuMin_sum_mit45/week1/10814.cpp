/////////////////////////////////////////////
//작성 날짜: 2021.04.07
//문제: 백준 10814)나이순 정렬
//기타: 커스텀 정렬, sort()사용 예제
/////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//age, name, join을 변수로 갖는 struct person 구성
struct person {
	int age;
	char name[102];
	int join;
} member[100000];


bool cmp(struct person a, struct person b) {
	if (a.age == b.age) { //나이 같다면 join 순대로
		return a.join < b.join;
	}
	else //나이 어린 순서대로
		return a.age < b.age;
}

int main() {
	int num;
	cin >> num; //멤버 수 입력

	for (int i = 0; i < num; i++) {
		scanf("%d" "%s", &member[i].age, member[i].name); //각 멤버 나이, 이름 입력
		member[i].join = i; //join순서 정하기
	}

	sort(member, member + num, cmp); 
	for (int j = 0; j < num; j++) {
		printf("%d %s\n", member[j].age, member[j].name);
	}
}
