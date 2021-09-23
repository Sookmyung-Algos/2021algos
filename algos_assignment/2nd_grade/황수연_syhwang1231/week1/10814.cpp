#include <iostream>
#include <algorithm>

using namespace std;

struct person	//나이, 이름, 가입 순서 저장할 person 구조체
{
	char name[102];
	int age;
	int order;	//가입한 순서
}people[100000];	//person 구조체 배열 생성

bool compare(struct person a, struct person b)	//구조체 a와b 나이 비교하는 함수
{
	if (a.age == b.age)
		return a.order < b.order;   //오름차순
	else
		return a.age < b.age;
}

int main(void)
{
	int n;	 //회원 수
	cin >> n;
	for (int i = 0; i < n; i++)		//나이와 이름을 n번 입력받기
	{
		cin >> people[i].age >> people[i].name;
		people[i].order = i;		//가입한 순서 저장
	}
	sort(people, people + n, compare);	//compare함수를 이용해 sort()

	for (int i = 0; i < n; i++)
	{
		cout << people[i].age << " " << people[i].name << "\n";
	}
	return 0;
}
