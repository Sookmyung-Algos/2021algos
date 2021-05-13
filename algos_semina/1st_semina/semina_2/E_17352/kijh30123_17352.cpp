#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	vector<int> v[300001];
	int flag[300001]; //배열지정 문제 최댓값이 300000이므로 300001로 지정
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); //입출력속도 개선

	int node, s, e, idx = 0;
	cin >> node;
	for (int i = 0; i < node - 2; i++) {
		cin >> s >> e;
		v[s].push_back(e); //양방향으로 넣음
		v[e].push_back(s);
	}
	queue<int> q;
	q.push(1); //가장 먼저 넣은게 빨리 나오도록
	flag[1] = 1;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {//v를 돌면서
			int next = v[cidx][i]; //돌수있는 곳
			if (flag[next] == 0) { //0이라고 되어있으면
				flag[next] = 1; //1로 저장
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= node; i++) {
		if (flag[i] == 0) { //안이어져있는 곳
			idx = i; //저장
			break;
		}
	}
	cout << 1 << " " << idx; //출력
	//하나만 부숴서 1로 고정해도 아무거나 출력이기때문에 정답
	return 0;
}
