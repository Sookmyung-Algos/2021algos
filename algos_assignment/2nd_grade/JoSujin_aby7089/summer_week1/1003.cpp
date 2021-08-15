#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
int t, n;
int zero[50] = { 1,0 }, one[50] = { 0,1 }; //fibo(0)과 fibo(1)이 몇번 불러졌는지 확인하는 배열

void fibo(int n) { 
	for (int i = 2; i <= n; i++) { //기존 코드는 시간초과 발생하나
		zero[i] = zero[i - 1] + zero[i - 2]; //이 코드는 이전 결과를 저장해놓기 때문에 새로 계산할 필요x
		one[i] = one[i - 1] + one[i - 2];
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		fibo(n);
		cout << zero[n] << " " << one[n] << "\n";
	}
}
