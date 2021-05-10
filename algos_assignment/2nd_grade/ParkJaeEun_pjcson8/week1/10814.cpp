#include <iostream>
#include <vector> //vector 사용
#include < algorithm> //sort 사용

using namespace std;

struct people {
	int age;
	char name[101];
	int join;
}member[100000]; 

bool cmp(struct people a, struct people b)
{
	if (a.age == b.age) //나이가 같을 경우 들어온 순서대로 정렬.
		return a.join < b.join; //b가 늦게 가입했으면 true
	else
		return a.age < b.age; //b의 나이가 더 많으면 true
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) //입력받기
	{
		cin >> member[i].age;
		cin >> member[i].name;
		member[i].join = i;
	}

	sort(member, member + n, cmp); //sort의 세번째 인자에 cmp를 넣어서 정렬.

	for (int i = 0; i < n; i++) //sorting 결과 출력하기
	{
		cout << member[i].age << " " << member[i].name << "\n";
	}
}
