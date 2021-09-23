#include<iostream> //cin, cout 사용
#include<map> //map 헤더
#include<vector> //vector 헤더
#include<string> //string 헤더
#include<algorithm> //algorithm 사용
using namespace std; //식별자가 고유하도록 보장

struct data //구조체 사용
{
	int age;
	string name; //cin으로 받아서 string으로 지정했습니다
	int date;
} m[100000]; 

bool cmp(struct data a, struct data b) { //커스텀 정렬함수입니다.
	if (a.age == b.age) return a.date < b.date; //가입한 순 오름차순으로
	return a.age < b.age; //나이 오름차순으로
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);//입출력개선
	int N;
	cin >> N; //값을 입력받습니다
	for (int i = 0; i < N; i++) { //data 갯수만큼 반복합니다
		int a;
		string n;
		cin >> a >> n; //나이, 이름 받습니다
		m[i].age = a; 
		m[i].name = n;
		m[i].date = i;
	}
	sort(m, m+N, cmp); //커스텀정렬 합니다
	for (int i = 0; i < N; i++) {
		cout << m[i].age << " " << m[i].name<<"\n"; //cout으로 출력합니다
	}
	return 0;
}
