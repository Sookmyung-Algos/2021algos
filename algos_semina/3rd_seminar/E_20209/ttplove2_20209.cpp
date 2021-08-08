// 큐브들 위에 쓰여 있는 숫자를 동일하게 만들기 위해
// 눌러야 되는 스위치의 최소 횟수

/*
1. i번 스위치를 누르면 해당 스위치와 연결된 모든 큐브의 숫자가 i만큼 증가
2. 큐브 숫자가 4를 초과하면 5로 나눈 나머지로 초기화
3. 한번에 한 개의 스위치만
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N, K, cnt = 0;
vector<int> cube;
vector<int> v[9];

bool issame(vector<int>& c)
{ // 큐브 값이 전부 같은 지 확인하는 함수
	int a = c[0];
	for (int i = 1; i < N; i++) {
		if (a != c[i]) return false;
	}
	return true;
}

vector <int> press(vector<int>& c, int n)
{ //스위치 누르기
	// 스위치 누른 후 변화된 큐브값을 벡터 형태로 반환함
	vector<int> newcube = c;
	for (int i = 0; i < v[n].size(); i++) {
		newcube[v[n][i] - 1] += n + 1;
		newcube[v[n][i] - 1] %= 5;
	}
	return newcube;
}

int bfs()
{
	map<vector<int>, int> m;
	// 큐브 정보 벡터와 스위치 누른 횟수를 저장하는 map 자료형
	queue<vector<int>> q;

	m[cube] = 0;
	q.push(cube);

	while (!q.empty()) {
		vector<int> cur = q.front();
		q.pop();
		cnt= m[cur];
		// 현재 카운트 값에 map에서 cur 벡터에 해당하는 int 값을 저장 

		if (issame(cur)) return cnt;
		// 만약 cur에 저장된 모든 값이 같다면 그대로 cnt 값을 반환
		for (int i = 0; i < K; i++) {
			vector<int> newc = press(cur, i);
			// 스위치를 누르고 난 후의 새로운 큐브
			if (m.find(newc) == m.end()) { 
				//map에 해당 벡터가 저장이 되어 있지 않다면
				m[newc] = cnt + 1;
				q.push(newc);
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		cube.push_back(n);
	}

	for (int i = 0; i < K; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int c;cin >> c;
			v[i].push_back(c);
		}
	}

	cout << bfs() << "\n";
	return 0;
}
