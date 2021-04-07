#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct Person {
	int age;
	string name;
	int join;
}; //구조체 Person에 나이, 이름, 가입 순서를 차례로 저장

bool compare(Person a, Person b) {
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
		return a.join < b.join;
	else
		return false;
} //나이를 기준으로 비교하며 나이가 같을 시 가입 순서를 따름

int main() {
	int N;
	cin >> N; //입력받을 회원의 수

	vector<Person> vec(N); //Person구조체를 저장하는 벡터

	for (int i = 0; i < N; i++) 
	{
		cin >> vec[i].age >> vec[i].name;
		vec[i].join = i;
	} //나이, 이름을 순서로 입력받으며 인덱스를 이용해 가입 순서 저장
  
	sort(vec.begin(), vec.end(), compare); //compare()함수를 이용해 정렬

	for (int i = 0; i < N; i++)
		cout << vec[i].age << " " << vec[i].name << "\n"; //sort()결과에 따라 벡터 출력
}
