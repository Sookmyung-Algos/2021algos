#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, double>m;  
int main() {
	ios_base::sync_with_stdio(false);  //동기화 끊어주고
	cin.tie(0); cout.tie(0);  //cin과 cout의 tie 끊어서 실행 속도 빠르게 해줌
	
	string species;  //각 줄에 나무의 종을 입력받기 위한 species 변수를 선언
	int count=0;   //입력받은 수를 세 줄 정수형 변수 count 선언 및 초기화

	while (getline(cin,species)) {   //입력받을 수가 정해져있지 않으므로 eof를 입력받기 전까지 반복하여 종의 이름을 입력받는 while 반복문
		count++;  //전체 개수 +해줌
		m[species] ++;   //종 각각의 개수 +해줌
	}
	cout << fixed;   //문제의 조건에 맞게 소수점을 고정시켜줌
	cout.precision(4);    //문제의 조건에 맞게 소수점 4째자리까지 표현하기 위함
	for (auto it = m.begin(); it != m.end(); it++) {   //iterator 사용해 map의 처음부터 끝까지 순회하는 for문
		string name = it->first; 
		double val = it->second;
		val /= count;  // 비율을 구해주기 위해 전체 개수로 나눈 다음
		val *= 100.0;   //백분율로 나타내기 위해 100을 곱해줌
		cout << name << ' ' << val << '\n';  //종의 이름과 그 종의 차지하는 비율 값을 예제 출력 형식에 맞게 출력하며 마무리
	}
	return 0;
}
