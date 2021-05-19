#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, time = 0;
	int p[1000];

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> p[i];

	sort(p, p + N);     //오름차순 정렬

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)    //i번째 사람이 돈 인출하는데 총 걸리는 시간 (기다리는 시간 포함)
			time += p[j];    //N명의 사람들이 돈 인출하는 데 걸리는 시간 합

	cout << time;
	return 0;
}
