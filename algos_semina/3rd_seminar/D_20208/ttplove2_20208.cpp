#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int N, M, H, result = 0;
typedef struct coordinate {
	int i;
	int j;
	bool visit;
}coordi;
coordi home;
vector<coordi> mint;

void solve(int y, int x, int cnt, int hp)
{
	if (result < cnt) {//
		if (abs(y - home.i) + abs(x - home.j) <= hp) 
			result = cnt;
	}

	if (hp <= 0) return;// 체력이 0보다 작거나 같으면 그대로 끝내준다

	for (int i = 0; i < mint.size(); i++) {
		// 민트초코우유가 있는 위치를 저장한 벡터의 크기만큼 반복함
		int tohome = abs(mint[i].i - y) + abs(mint[i].j - x);
		// 입력받은 지점에서 우유가 있는 곳으로 이동하기 위해 필요한 최소한의 체력을 나타내는 변수
		if (tohome <= hp && mint[i].visit == 0) {
			//현재 체력이 필요한 양보다 같거나 많고, 아직 방문하지 않은 상태라면
			mint[i].visit = 1; //방문 처리
			solve(mint[i].i, mint[i].j, cnt + 1, hp - tohome + H); //재귀 함수
			// 현재 위치를 시작 주소로 넣고, 카운트 값을 하나 더해주고, 체력에 이동한 만큼 체력을 빼주고 우유를 마셨으니 그만큼 체력을 뺀다.
			mint[i].visit = 0;// 다시 방문하지 않음을 표시해준다.
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a = 0;
			cin >> a;
			if (a == 1) {
				home.i = i;
				home.j = j;
				home.visit = false;
			}
			if (a == 2) mint.push_back({ i, j, 0 });
		}
	}

	solve(home.i, home.j, 0, M); // 현재 집 위치에서 시작

	cout << result << "\n";
	return 0;
}
