#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>graph[200002];
queue<int>q, sq;
int mark[200002]={0};

void bfs(){
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		for(int i=0;i<graph[tmp].size();i++){
			int x= graph[tmp][i];
			if(mark[x]!=-1) continue;	
			int cnt=0;
			for(int j=0; j<graph[x].size(); j++){
				if(mark[graph[x][j]]!=-1) cnt++;
			}
			if(graph[x].size()>cnt*2) continue;
			sq.push(x);
		}
		if(q.empty()){
			while(!sq.empty()){
				int temp= sq.front();
				sq.pop();
				mark[temp]= mark[tmp]+1;
				q.push(temp);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, start;
	for(int i=0; i<200001; i++){
		mark[i]=-1;
	}
	cin >> n;
	for(int i=1; i<=n; i++){
		while(1){
			int t;
			cin >> t;
			if(t==0) break;
			graph[i].push_back(t);
		}
	}
	cin >> start;
	for(int i=0; i<start; i++){
		int num;
		cin >> num;
		mark[num]=0;
		q.push(num);
	}
	bfs();
	for(int i=1;i<=n;i++){
		cout<<mark[i]<<' ';
	}
	return 0;
}
