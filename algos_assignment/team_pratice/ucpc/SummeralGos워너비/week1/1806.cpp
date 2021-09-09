//#1806
#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int num[100000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int j = 0; j < n; j++) {
		cin >> *(num + j);
	}


	//투포인터 알고리즘

	int left = 0, right = 0; //해당 수열의 맨 왼쪽과 맨 오른쪽 변수
	int sum = num[0]; //해당 수열의 총 합
	int result = n + 1; //해당 수열의 길이

	while (left <= right && right < n) {
		if (sum < s) { //s보다 작다면 오른쪽 원소 하나 더 포함
			sum += num[++right];
		}
		else if (sum == s) { //s와 같다면 현재의 원소의 개수와 기존 result 값 중 작은 값을 result에 새로 저장
			result = min(result, (right - left + 1));
			sum += num[++right]; //오른쪽 원소 하나 더 포함
		}
		else if (sum > s) {
			result = min(result, (right - left + 1));
			sum -= num[left++]; //s보다 크니까 왼쪽 원소 하나 제외
		}
	}

	if (result > n) //result가 n보다 크다면(합이 s인 수열이 존재하지 않는다면)
		cout << 0 << endl;
	else //존재한다면
		cout << result << endl;
	return 0;
}
