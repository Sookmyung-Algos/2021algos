#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int field[51][51] = {0, };
bool c[51][51] = {0, };
int prow[4] = { -1, 0, 1, 0 };
int pcol[4] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;
int t, n, m, k;

void bfs(int x, int y){
	c[x][y] = 1;
	q.push({x, y});

	while(!q.empty()){
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x2 = x1 + prow[i];
			int y2 = y1 + pcol[i];

			if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && field[x2][y2] == 1 && c[x2][y2] == 0) {
				q.push({ x2, y2 });
				c[x2][y2] = 1;
				
			}
		}
	}
}

int main() {
 
  cin>>t;

  while(t--){
	  cin>>m>>n>>k;
	  int count = 0;
	  memset(c,0,sizeof(c));
	  memset(field,0,sizeof(field));

	  for(int i = 0; i<k; i++){
		  int x, y;
		  cin>>x>>y;
		  field[x][y] = 1;
	  }

	  for(int i = 0; i<m; i++){
		  for(int j = 0; j<n; j++){
			  if(field[i][j] == 1 && c[i][j] == 0){
				bfs(i, j);
			  	count++;
			  }
		  }
	  }
	  cout<<count<<"\n";
  }
}
