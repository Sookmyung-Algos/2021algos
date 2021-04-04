#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

struct person
{
	int age;
	char name[101];
	int join;
};

bool cmp(struct person a, struct person b)
{
	if (a.age == b.age)	return a.join < b.join;
	else return a.age < b.age;

}

int main()
{
	int N, num = 1;
	struct person M[100001];
	cin >> N;
	for (int i = 0; i < N; i++, num++) {
		cin >> M[i].age >> M[i].name;
		M[i].join = num;
	}
	sort(M, M + N, cmp);
	for (int i = 0; i < N; i++) {
		printf("%d %s\n", M[i].age, M[i].name);
	}
	return 0;
