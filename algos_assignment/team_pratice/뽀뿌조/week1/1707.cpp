#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[20001];

int visited[20001];
int cnt1,cnt2;
bool hi=true;
queue<int> q;

void bfs(int x){
	q.push(x);
	visited[x]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0; i<g[now].size();i++){
			int next=g[now][i];
			if(visited[next]!=0 && visited[now]==visited[next]){
				cout<<"NO"<<"\n";
				hi=false;
				return;
			}
			if(visited[next]>0) continue;
			q.push(next);
			visited[next]=visited[now]%2+1;
		}
	}
}

int main(void){
	int n;
	cin>>n;
	while(n--){
		cin>>cnt1>>cnt2;
		for(int i=0;i<cnt2;i++){
			int v,e;
			cin>>v>>e;
			g[v].push_back(e);
			g[e].push_back(v);	
			
		}
		for(int i=1;i<=cnt1;i++){
			if(visited[i]==0){
				bfs(i);
				if(!hi) break;
			}
		}
		if(hi) cout<<"YES"<<"\n";
		while(!q.empty()) q.pop();
		for(int i=1;i<=cnt1;i++){
			visited[i]=0;
			g[i].clear();
		}
		hi=true;
	}
	return 0;
}
