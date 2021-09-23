#include <iostream>

using namespace std;

int N, maxNum = 0;;
int A[8];
int answer[8];
bool visit[8];

void next_one(int depth) {
	if (depth == N) { // N개 다 뽑았으면
		int tmp = 0;
		for (int i = 0; i < N - 1; i++) {
			tmp += abs(answer[i] - answer[i + 1]);
		}
		if (tmp > maxNum)
			maxNum = tmp;
		return;
	}

	for (int i = 0; i < N; i++) {  //N개 각 자릿구 값 선택하기
		if (visit[i])
			continue;
		visit[i] = true;
		answer[depth] = A[i];
		next_one(depth + 1);
		visit[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	next_one(0);

	cout << maxNum << '\n';
}
