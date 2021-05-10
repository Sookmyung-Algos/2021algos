#include<iostream>
#define MAX 300001
using namespace std;
int original[MAX];

int find(int x) {
	if (original[x] == x)
		return x;
	else
		return original[x] = find(original[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	original[y] = x;
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // 시간

	int n; 
	cin >> n;

	// 모든 수가 있는 배열 만들기
	for (int i = 0; i < n; i++)
		original[i] = i;

	for (int i = 0; i < n - 2; i++) {
		int a, b; 
		cin >> a >> b; // 두 숫자 입력받기 
		merge(a, b); 
	}

	// 1과 이어지지 않은 수 출력
	for (int i = 2; i <= n; i++) {
		if (!isUnion(1, i)) {
			cout << 1 << " " << i;
			return 0;
		}
	}
	return 0;
}
