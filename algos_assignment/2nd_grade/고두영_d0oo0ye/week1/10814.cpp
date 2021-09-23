#include <iostream>
#include <algorithm>

using namespace std;

struct person {
	int age;
	char name[101];
	int join;
} m [100000];

bool cmp(struct person a, struct person b) {
	if (a.age == b.age)
		return a.join < b.join;
	else
		return a.age < b.age;
}

int main()
{
	int n, i, j;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> m[i].age >> m[i].name;
		m[i].join = 1;
	}
	sort(m, m + n, cmp);
	for (j = 0; j < n; j++)
		cout << m[j].age << " " << m[j].name << "\n";
}
