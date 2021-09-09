//AC
//BOJ 2150 Strongly Connected Component
//https://www.acmicpc.net/problem/2150
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
vector<int> v[10001];
vector<int> r_v[10001];
stack<int> s;
vector<vector<int> > scc;
vector<int> temp;
bool visit[10001];
int vertex,e;
void dfs(int start){
	visit[start] = true;
	for(int i=0; i<v[start].size(); i++){
		int x = v[start][i];
		if(!visit[x]){
			dfs(x);
		}
	}
	s.push(start);
}
void re_dfs(int start, int y){
	visit[start] =true;
	temp.push_back(start);
	for(int i=0; i<r_v[start].size(); i++){
		int x = r_v[start][i];
		if(!visit[x]){
			re_dfs(x, y);
		}
	}
}
int main(){
	int cnt = 0, idx = -1;
	cin >> vertex >> e;
	for(int i=0; i<e; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		r_v[b].push_back(a);
	}
	for(int i=1; i<=vertex; i++){
		if(!visit[i]){
			dfs(i);
		}
	}
	memset(visit, false, sizeof(visit));
	while(!s.empty()){
		int x = s.top();
		s.pop();
		if(!visit[x]){
			re_dfs(x, x);
			sort(temp.begin(),temp.end());
			scc.push_back(temp);
			temp.clear();
			cnt++;
		}
	}
	sort(scc.begin(), scc.end());
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++){
		for(int j=0; j<scc[i].size(); j++){
			printf("%d ", scc[i][j]);
		}
		printf("%d\n", idx);
	}
	return 0;
}
