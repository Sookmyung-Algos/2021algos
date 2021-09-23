//#11399 atm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, time, temp, bef=0,sum = 0;
	vector<int> v; //int형 vector v 선언

	cin >> n; //사람의 수 입력
	for (int i = 0; i < n; i++) { //n개의 시간을 변수 time에 입력받아 vector v에 저장
		cin >> time;
		v.push_back(time);
	}
	sort(v.begin(), v.end()); //시간을 오름차순 정렬

	for (int i = 0; i < n; i++) {
		temp = bef + v[i]; //i+1번째 이전의 사람들이 인출한 시간과 i+1번째 사람이 인출하는 시간을 합하여 temp에 대입
		bef = temp; //temp를 bef에 대입
		sum += temp; //sum에 temp값까지 합함
	}
	cout << sum; //걸리는 시간의 합의 최솟값 sum 출력
}
