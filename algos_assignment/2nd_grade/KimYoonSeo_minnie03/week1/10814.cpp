#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
	int age;
	char name[102];
	int seq;
}member[100000];

bool cmp(struct person a, struct person b) {
	if (a.age == b.age) {//a와 b의 나이를 비교하여 나이가 같다면
		return a.seq < b.seq;//순서가 뒤인 b가 뒤에 올때 true 리턴
	}
	else {//같지 않다면
		return a.age < b.age; //나이가 더 많은 사람이 뒤일때 true 리턴
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin>>member[i].age>>member[i].name;
		member[i].seq = i;
	}

	sort(member, member + n, cmp);
	for (int i = 1; i <= n; i++) {
		cout << member[i].age << " " << member[i].name<<"\n";
	}
}
