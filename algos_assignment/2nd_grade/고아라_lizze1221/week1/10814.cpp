#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 사용을 위해 추가

using namespace std;


struct Person {
	int age;
	string name;
	int join;
};

bool cmp(Person a, Person b) {
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		return a.join < b.join;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	vector<Person> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].age >> vec[i].name;
		vec[i].join = i;
	} // 나이와 이름을 입력받기

	sort(vec.begin(), vec.end(), cmp); 
	// sort 함수를 이용해 나이 순으로 정렬하기

	for (int i = 0; i < N; i++) {
		cout << vec[i].age << " " << vec[i].name << "\n";
	}

}
