#include <iostream>
#include<vector>// vector를 위해 vector 헤더를 사용
#include <algorithm>//sort를 위해 algorithm 헤더를 사용
using namespace std;
struct people {
	int age;
	char name[101];
	int join;
} member[100000];

bool cmp(struct people a, struct people b) {
	if (a.age == b.age) {//나이가 같을 경우 들어온 순서로 정렬해야함
		return a.join < b.join;//만약 a.join>b.join 이라면 false가 반환되므로 a와 b의 위치가 바뀔것
	}
	else {
		return a.age < b.age;//위와 같이 a.age>b.age라면 a와b의 위치 바뀔것
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> member[i].age;
		cin >> member[i].name;
		member[i].join = i;
	}
	sort(member, member + n, cmp); //sort를 이용해 정렬
	for (int i = 0; i < n; i++) {
		cout << member[i].age <<" "<< member[i].name << "\n";
	}
}
