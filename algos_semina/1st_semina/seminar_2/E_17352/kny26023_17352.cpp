#include<iostream>
#define MAX 300001
using namespace std;
int bridge[MAX];

int find(int x) {
	if (bridge[x] == x)
		return x;
	return bridge[x] = find(bridge[x]);
}
//bridge[x]가 x와 같아질 때까지 find를 해준다.

void change(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	bridge[y] = x;
}
//x와 y를 find로 처리해준 후, x와 y가 같다면 그냥 return, 아니라면 brigde[y]를 x로 넣어주는 작업을 처리한다.

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}
//x와 y를 find로 처리해준 후, x와 y가 같다면 true를, 아니라면 false를 return해준다. 결국 같은지 아닌지 확인하는 작업이다.

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//속도를 빠르게 하기 위함이다.
	int n;
	cin >> n;
	for (int i = 0; i < MAX; i++)
		bridge[i] = i;
	//brigde에 0부터 MAX까지의 수를 넣어준다.
	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		change(a, b);
	}
	//0부터 n-2까지 a, b를 받아준 후(이어지는 다리) change해준다.
	for (int i = 2; i <= n; i++) {
		if (!isUnion(1, i)) {
			cout << 1 << " " << i;
			return 0;
		}
	}
	//이어져 있지 않으면 1과 i를 print해주고(여러 가지 방법이 있겠으나 여기서는 1과 i를 잇는 걸로 한다.)
	//아니면 아무것도 print해주지 않는다.
	return 0;
}
