#include <iostream>
#include <algorithm>
using namespace std;
// 오름차순 정렬을 하는 경우 최소 시간이 걸린다
int main() {
	int n; // 줄울 서 있는 사람의 수
	int time[1001]; // 각 사람이 돈을 인출하는데 걸리는 시간
	int sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> time[i];
	sort(time, time + n); // 오름차순 정렬

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)	sum += time[j];
	}
	cout << sum;

	return 0;
}
