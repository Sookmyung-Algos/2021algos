#include<iostream>
#include<algorithm>
#include<queue>
#include<vector> 
using namespace std;

int N,M;
int x, y;
int board[2000][2000];
int visit[2000];
int bfs_cnt=0;

void bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	visit[cur]=2; 

	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if(board[cur][i] && visit[i]!=2)
			{
				visit[i]=2;
				q.push(i);
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> M;

	for(int i=1;i<=M;i++)
	{
		cin >> x >> y;
		board[x][y]=board[y][x]=1;
	}
	
	for(int rx=1;rx<=N;rx++)
	{
		if(visit[rx]==0)
		{
			bfs(rx);
			bfs_cnt++;
		}
		
	}

	cout << bfs_cnt;
	
	return 0;

}
