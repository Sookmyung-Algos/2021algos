//브루트포스 알고리즘
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int num[20001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	sort(num, num + n); //입력받은 수들을 정렬한 후
	cout << num[(n - 1) / 2]; //n이 홀수이면 중앙값 or n이 짝수이면 가운데 위치한 두 수 중 작은 수 
}
