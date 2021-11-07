#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int n, cnt1, cnt2;
vector<int> v[11];
int pnum[11], visit[11], visitv1[11], visitv2[11];
int ans = 987654321;
int flag = 0;

void chk1(vector<int> g, int a, int b){  //1 연결 확인
	cnt1++;
	visitv1[a] = 1;
	for (int i = 0; i < v[a].size(); i++){
		if (visit[v[a].at(i)] == 1)
			if (visitv1[v[a].at(i)] == 0)
				chk1(g, v[a].at(i), b);
	}
}

void chk2(vector<int> g, int a, int b){  //2 연결 확인
	cnt2++;
	visitv2[a] = 1;
	for (int i = 0; i < v[a].size(); i++){
		if (visit[v[a].at(i)] == 0)
			if (visitv2[v[a].at(i)] == 0)
				chk2(g, v[a].at(i), b);
	}
}

void dfs(int now, int num){  //선거구 나누기
	if (num == n + 1){
		int num1 = 0, num2 = 0, ans1 = 0, ans2 = 0;
        vector <int> v1, v2;
		cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++){
			if (visit[i] == 1){
				v1.push_back(i);
				num1++;
				ans1 += pnum[i];
			}
			else{
				num2++;
				v2.push_back(i);
				ans2 += pnum[i];
			}
		}
		if (v1.size() > 0 && v2.size() > 0){  //적어도 1개의 구역을 가져야 함
			memset(visitv1, 0, sizeof(visitv1));
			memset(visitv2, 0, sizeof(visitv2));
			chk1(v1, v1.at(0), 1);
			chk2(v2, v2.at(0), 1);
		}
		if (num1 == cnt1 && num2 == cnt2){  //인구 차이의 최솟값 구하기
			flag = 1;
			ans = min(ans, abs(ans1 - ans2));
		}
		return;
	}
	visit[now] = 1;
	dfs(now + 1, num + 1);
	visit[now] = 0;
	dfs(now + 1, num + 1);
}

int main(){
	int m, a;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> pnum[i];
	for (int i = 1; i <= n; i++){
		cin >> m;
		for (int j = 0; j < m; j++){
			cin >> a;
			v[i].push_back(a);
			v[a].push_back(i);
		}
	}
	dfs(1, 1);
	if (flag == 1)
		cout << ans;
	else
		cout << "-1";
}
