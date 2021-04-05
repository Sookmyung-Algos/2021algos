#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person //구조체 이용 나이, 이름, 가입 순서 저장
{
	int age;
	char name[102];
	int join;
} member[100000];

bool cmp(struct person a, struct person b)
{
	if (a.age == b.age) //나이가 같으면 먼저 들어온 순
		return a.join < b.join;
	else // 아니면 나이 순
		return a.age < b.age;
}

int main(int argc, const char * argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { //n의 크기에 따라 입력 값 저장 => 들어온 순서 가늠
		scanf("%d" "%s", &member[i].age, member[i].name);
		member[i].join = i;
	}
	sort(member, member + n, cmp); //정렬
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", member[i].age, member[i].name);
	}
}
