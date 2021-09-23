#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person {
	int age;
	char name[102];
	int join; // 가입한 순서
} member[100000];

bool cmp(struct person a, struct person b) {
	if (a.age == b.age)	return a.join < b.join; //나이가 같으면 먼저 가입한 사람이 앞으로
	else return a.age < b.age; //나이가 적은 사람이 먼저
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d" "%s", &member[i].age, member[i].name); //나이, 이름 입력받기
		member[i].join = i;
	}
	sort(member, member + n, cmp); //cmp함수 이용하여 정렬
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", member[i].age, member[i].name); //정렬한 값 출력
	}

	return 0;
}
