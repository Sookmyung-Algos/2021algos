#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int n,m;
int b[MAX][MAX];

struct P{
    int x;
    int y;
    int c;
};

struct cmp{
    bool operator()(P a, P b){
        return a.c > b.c;
    }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(){
    int v[MAX][MAX]={0};
    priority_queue<P, vector<P>, cmp> pq;
    
    int start = b[0][0];
    if(start==-1) 
        return -1;
    if(start==0) 
        pq.push({0,0,0});
    if(start==1) 
        pq.push({0,0,1});
    if(start==2) 
        pq.push({0,0,2});
    v[0][0]=1;
    
    while(!pq.empty()){
        P p = pq.top();
        int x = p.x;
        int y = p.y;
        int c = p.c;
        pq.pop();
        if(x==n-1 && y==m-1)
            return c;
        
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && xx < n && yy < m){
                int k = b[xx][yy];
                if(v[xx][yy]==0 && b[xx][yy]!=-1){
                    v[xx][yy]=1;
                    if(k==0)
                        pq.push({xx,yy,c});
                    if(k==1)
                        pq.push({xx,yy,c+1});
                    if(k==2)
                        pq.push({xx,yy,c+2});
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> b[i][j];
        }
    }
    cout << bfs();
    return 0;
}
