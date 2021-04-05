#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

struct person {
	int age;
	char name[101];
	int order;
} member[100000]; //member라는 struct를 만들어준다

bool cmp(struct person a, struct person b) {  //a와 b가 있을 때
	if (a.age == b.age) //a와 b의 age가 같으면 가입 순서를 비교한 bool을 리턴한다
		return a.order < b.order;
	else
		return a.age < b.age; //같지 않으면 age를 비교한 bool을 리턴한다
}

int main() {
	int i, n;
	scanf("%d", &n);  
	for (i = 0; i < n; i++) {
		scanf("%d %s", &member[i].age, member[i].name); //scanf를 할 때 member[i].age에 &를 넣어주는 것을 잊지 말아야 한다
		member[i].order = i;  //order는 입력된 순서이므로 i번째가 들어가면 된다
	}
	sort(member, member + n, cmp);  //cmp에 따라 sort를 해준다
	for (i = 0; i < n; i++) {
		printf("%d %s\n", member[i].age, member[i].name); //sort한 결과를 print해준다
	}
	return 0;
}
