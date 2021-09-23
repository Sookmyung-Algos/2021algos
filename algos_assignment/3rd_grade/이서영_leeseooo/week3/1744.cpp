#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
	int n, num;
	vector<int>plusNum;
	vector<int>minusNum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > 0) plusNum.push_back(num);// 0제외 양수는 양수벡터에
		else minusNum.push_back(num);// 0포함 음수는 음수벡터에 저장
	}
	sort(plusNum.begin(), plusNum.end());
	sort(minusNum.begin(), minusNum.end());

	int ans = 0;
	for (int i = plusNum.size()-1; i >= 0; i -= 2) {// 2개씩 살펴봄(곱셈or덧셈 중 합이 더 큰 결과를 저장)
		int mul = 1;
		int sum = 0;
		mul *= plusNum[i]; sum += plusNum[i];// 초기값 넣어주고
		if (i - 1 >= 0) {//2개씩 건너뛰므로 1개 남았을 때를 고려해줌
			mul *= plusNum[i - 1]; sum += plusNum[i - 1];// 그 다음 수와 묶어줌
		}
		ans += max(mul, sum); // 곱셈과 덧셈 중 더 큰 값을 더해줌
	}
	for (int i = 0; i < minusNum.size(); i += 2) {//음수는 곱셈이 무조건 이득이다.
		int mul = 1;
		mul *= minusNum[i];
		if (i + 1 < minusNum.size()) {//1개 남았을때
			mul *= minusNum[i + 1];
		}
		ans += mul;
	}
	cout << ans;
}
