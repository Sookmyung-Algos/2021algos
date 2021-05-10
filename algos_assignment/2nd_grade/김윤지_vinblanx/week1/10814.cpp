#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct person { //구조체를 선언하여 사람 별 정보 저장
	int age;
	char name[101];
	int join;
} member[100000]; //온라인 저지 회원의 수 100000만큼 공간 확보

bool cmp(struct person a, struct person b) { //비교하고자 하는 타입과 같은 타입의 데이터 두 개 입력 받기
	if (a.age == b.age) //나이가 같다면
		return a.join < b.join; //b의 가입 순서가 더 늦을 때 true 리턴
	else //나이가 다르다면
		return a.age < b.age; //b의 나이가 더 많을 때 true 리턴
}

int main(int args, const char* argv[]) {
	int N; //온라인 저지 멤버 수 입력 받을 변수 선언
	scanf("%d", &N); //온라인 저지 멤버 수 입력 받기

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &member[i].age, &member[i].name); //i번째 멤버 나이와 이름 입력 받기
		member[i].join = i; //i번째 멤버 가입 순서 저장
	}

	sort(member, member + N, cmp); //cmp를 이용한 정렬

	for (int i = 0; i < N; i++) { //멤버의 수만큼
		printf("%d %s\n", member[i].age, member[i].name); //cmp를 통해 정렬된 멤버 정보 출력
	}

	return 0;
}
