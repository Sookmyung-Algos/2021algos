#include <iostream>
#include <algorithm>
#include<queue>
#include <vector>
using namespace std;
int N, S, A[100001],minN;
int tmp;
int ans(int a, int b) {//유클리드 호제법
	if (b == 0)return a;
	else
		return ans(b, a % b); //수빈과 동생 사이 거리들의 최대공약수 찾기
}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tmp = abs(S - tmp);//절대값
		A[i] = tmp;
	}
	minN = A[0];
	for (int i = 1; i < N; i++) {
		minN = ans(minN, A[i]);
	}
	cout << minN;
}
