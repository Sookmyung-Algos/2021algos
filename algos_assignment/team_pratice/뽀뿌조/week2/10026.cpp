#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

char arr[101][101];
bool visit[101][101] = {false, };
int dx[4] = { -1, 0, 1, 0 }; //시계방향
int dy[4] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;
int cnt = 0;
int ncnt = 0;
int n;

void bfs(int a, int b);

int main(){

  cin>>n;

  for(int i=0; i<n; i++){
    for(int j = 0; j<n; j++){
      cin>>arr[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(visit[i][j] == false){
        bfs(i, j);
        cnt++;
      }
    }
  }

  memset(visit, false, sizeof(visit));

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(arr[i][j] == 'G' || arr[i][j] == 'R'){
        arr[i][j] = 'N';
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(visit[i][j] == false){
        bfs(i, j);
        ncnt++;
      }
    }
  }

  cout<<cnt<<" "<<ncnt;

  return 0;

}

void bfs(int a, int b) {
  q.push({a, b});
  visit[a][b] = true;

	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		int x2, y2;
		for (int i = 0; i < 4; i++) {
			x2 = x1 + dx[i];
			y2 = y1 + dy[i];

			if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && visit[x2][y2] == false) { //방문하지 않았고
				if(arr[x1][y1] == arr[x2][y2]){ //현재 칸과 같은 색깔이면
          visit[x2][y2] = true;
          q.push({x2, y2});
        }
			}
		}

	}
}
