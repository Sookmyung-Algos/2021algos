//꼭 다시 복습해볼 것
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int num[10]; //리모콘의 고장난 숫자 버튼

bool possible(int x);
int find(int x);

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int temp;
		cin >> temp;
		num[temp] = 1;
	}
	cout << find(n);
	return 0;
}
bool possible(int x) { //버튼을 누른 횟수
	if (x == 0)	return num[0] ? false : true;
	while (x) {
		if (num[x % 10] == 1)	return false;
		x /= 10;
	}
	return true;
}
int find(int x) {
	int hund = abs(x - 100), button = 1000007;
	for (int i = 0; i <= 1000007; i++) {
		if (possible(i)) { //버튼을 누른 횟수
			int temp = to_string(i).length(); //+,-를 해야하는 횟수
			temp += abs(i - x); //저장
			button = (button < temp ? button : temp);
		}
	}
	return hund < button ? hund : button; //가장 횟수가 적은 방법 반환
}
