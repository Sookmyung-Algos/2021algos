#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool c[51] = {false, };
vector<int> v[51];
int n, m;
int ans = 0;
queue <int> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		c[x] = true;
		for (int i = 0; i < v[x].size(); i++) {
			int x2 = v[x][i];
			if(c[x2]){
				continue;
			}
			q.push(x2);
		}

	}
}


int main() {
  cin>>n;

  for(int i = 0; i<n; i++){
	  cin>>m;
	  if(m == -1){
		  continue;
	  }
	  v[m].push_back(i);
  }

  cin>>m;
  q.push(m); c[m] = true;
  bfs();
  
  for(int i = 0; i<n; i++){
	  if(c[i] == false){
		  int j;
		  for(j = 0; j<v[i].size(); j++){
			  if(!c[v[i][j]]) break;
		  }
		  if(j == v[i].size()) ans++;
	  }
  }
  cout<<ans<<endl;
}
