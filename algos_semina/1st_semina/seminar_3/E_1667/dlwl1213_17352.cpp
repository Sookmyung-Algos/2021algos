#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[300001];  //N의 크기는 300000 이하
int flag[300001];   //마을들을 0,1에 속하는 마을로 배열을 통해 나눠주기 위함

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int node, s, e, idx = 0;
	cin >> node;
	for (int i = 0; i < node - 2; i++) {  //n-2개까지 받아줌
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	queue<int> q;
	q.push(1);
	flag[1] = 1;  //처음에 무조건 1을 출력하도록 고정
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (flag[next] == 0) {
				flag[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= node; i++) {   //flag 배열의 값 중 0인 부분을 임의로 1개 idx에 저장 후 출력해줌
		if (flag[i] == 0) {
			idx = i;
			break;
		}
	}
	cout << 1 << " " << idx;
	return 0;
}
