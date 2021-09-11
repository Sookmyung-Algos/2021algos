#include <iostream> 
#include <queue>
using namespace std; 
bool visit[101] = { 0, };
int depth[101] = { 0, };
int a[101][101] = { 0, };
int n;
void bfs(int start){ 
	queue<int> q;
	q.push(start); 
	visit[start] = true; 
	while(!q.empty()){ 
		int tmp = q.front(); q.pop(); 
		for(int i=1; i<=n; i++){ 
			if(a[tmp][i]&&!visit[i]){ 
				visit[i] = true;
				q.push(i);
				depth[i] = depth[tmp] + 1;
			} 
		} 
	} 
} 
int main(void){
	int p1, p2,m,x,y;
	cin >> n;
	cin >> p1 >> p2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y]=1;
		a[y][x]=1;
	}
	bfs(p1); 
	if (depth[p2] != 0)
		cout << depth[p2] << '\n';
	else
		cout << "-1" << '\n';
	return 0; 
}
