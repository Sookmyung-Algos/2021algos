#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char map[1000][1000];
bool vis[1000][1000];
int dir[4][4]={{0, 1}, {-1, 0}, {0, -1}, {1,0}};
vector<pair<int,int>> fire;
int w, h;
int sr, sc;
int minT;

void bfs(){
	queue<pair<bool, pair<int,int>>> q;
	for(int i=0;i<fire.size();i++){
		q.push({false, fire[i]});
	}
	q.push({true, {sr, sc}});
	q.push({false, {-1,-1}});
	vis[sr][sc]=true;
	int cnt=1;
	while(!q.empty()){
		bool p=q.front().first;
		pair<int,int> loc=q.front().second;
		q.pop();
		if(loc.first==-1){
			cnt++;
			if(!q.empty())
				q.push({false, {-1, -1}});
			continue;
		}
		if(p&&(loc.first==0||loc.first==h-1||loc.second==0||loc.second==w-1)){
			if(minT>cnt) minT=cnt;
		}
		if(p){
			for(int i=0;i<4;i++){
				int nr=loc.first+dir[i][0];
				int nc=loc.second+dir[i][1];
				if(nr<0||nr>=h||nc<0||nc>=w||vis[nr][nc]==true||map[nr][nc]!='.') continue;
				vis[nr][nc]=true;
				q.push({true, {nr,nc}});
			}
		}
		else{
			for(int i=0;i<4;i++){
				int nr=loc.first+dir[i][0];
				int nc=loc.second+dir[i][1];
				if(nr<0||nr>=h||nc<0||nc>=w||map[nr][nc]=='#'||map[nr][nc]=='*') continue;
				vis[nr][nc]=true;
				map[nr][nc]='*';
				q.push({false, {nr,nc}});
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t>0){
		cin >> w >> h;
		fill(&vis[0][0], &vis[999][1000], false);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin >> map[i][j];
				if(map[i][j]=='@'){
					sr=i; sc=j;
				}
				else if(map[i][j]=='*')
					fire.push_back({i, j});
			}
		}
		minT=0x7fffffff;
		bfs();
		if(minT==0x7fffffff) cout << "IMPOSSIBLE\n";
		else cout << minT << "\n";
		fire.clear();
		t--;
	}
}
