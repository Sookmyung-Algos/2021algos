#include<iostream>
#define MAX 300001
using namespace std;
int brd[MAX];

int find(int x) {
	if (brd[x] == x)
		return x;
	return brd[x] = find(brd[x]);
}

void merge(int x, int y) {    //섬을 두 그룹으로 나누기
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	brd[y] = x;
}

bool isUnion(int x, int y) {   //x와 y가 같은지 확인
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < MAX; i++)
		brd[i] = i;
	for (int i = 0; i < n - 2; i++) {
		int a, b; 
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 2; i <= n; i++) {   
		if (!isUnion(1, i)) {
			cout << 1 << " " << i;      //1과 연결시킨다고 가정하고 이어져 있지 않으면 출력
			return 0;
		}
	}
	return 0;
}
