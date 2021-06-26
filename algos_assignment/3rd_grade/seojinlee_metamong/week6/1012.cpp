#include <iostream> 
using namespace std; 
int m,n,k;
int map[60][60];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; 
void init()
{
	for(int i=0; i<60; ++i) {
		for(int j=0; j<60; ++j) {
			map[i][j]=0;
		}
	}
}
 
void DFS(int a, int b)
{
	if (map[a][b]==1) {
		map[a][b]=0;
		for (int hi=0; hi<4; ++hi){
			int x=dx[hi]+a;
			int y=dy[hi]+b;
			if(x>=0 && y>=0 && x<m && y<n) {
				DFS(x, y);
			}
		}
	}
}
 
int main(int argc, char *argv[])
{
	int a,b;
	int cnt;
	int num;
	cin>>num;
	while(num--) {
		init();
		cnt=0;
		cin>>m>>n;
		cin>>k;
		for(int i=0; i<k; ++i) {
			cin>>a>>b;
			map[a][b]=1;
		}
		for(int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (map[i][j] == 1) {
					DFS(i, j);
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
