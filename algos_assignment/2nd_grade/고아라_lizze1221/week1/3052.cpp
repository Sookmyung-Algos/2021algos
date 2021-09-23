#include <iostream>
#include <set>

using namespace std;

int main() {
	set <int> remainder; 
	// set은 중복 값을 받지 않기 때문에 문제에 적절

	int num[10];
	int count = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num[i]; // 숫자 입력받기
		remainder.insert(num[i] % 42);
		// 나머지 값을 reaminder에 넣기
	}
	
	cout << remainder.size(); 
	// remainder의 사이즈 출력

	return 0;
}
