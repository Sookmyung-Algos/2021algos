#include <iostream>
using namespace std;

int num[11] = { 0, }; //num배열로 각 양수의 dp값 저장

int dp(int k) {
	if (k == 1) return 1;
	else if (k == 2) return 2;
	else if (k == 3) return 4;
	else if (num[k] != 0) return num[k]; //만약 num에 dp값이 저장되어 있다면 그대로 num 리턴
    return num[k] = dp(k - 1) + dp(k - 2) + dp(k - 3); //위 경우 외의 경우라면 새로 num에 값 저장 후 리턴
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t,n;
	cin >> t;
	for (int i = 0; i < t; i++) { //t번의 테스트 케이스동안
		cin >> n;
		int result=dp(n); //result에 dp값 저장
		cout << result << endl;
	}
	return 0;
}
