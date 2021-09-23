#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string map[26];
int cnt=0;
vector <int> h;

int dx[]={1,-1,0,0};        //상하좌우 좌표
int dy[]={0,0,1,-1};

void dfs(int x,int y);

int main(){
    
    cin>>N;
    for (int i=0;i<N;i++){
            cin>>map[i];
    }
    
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if (map[i][j]=='1'){
                map[i][j]='2';          //방문한 노드임을 표시
                cnt=1;                  //단지 내 집 수
                dfs(i,j);
                h.push_back(cnt);
            }
        }
    }
    sort(h.begin(),h.end());
    cout<<h.size()<<'\n';           //단지 수
    for(int i=0;i<h.size();i++)     //단지 내 집 수 오름차순
        cout<<h[i]<<'\n';
}

void dfs(int x,int y){
    int nx,ny;
    
    for (int i=0;i<4;i++)           //상하좌우 집
    {
        nx=x+dx[i];
        ny=y+dy[i];
        
        if (nx<0||ny<0||nx>=N||ny>=N)
            continue;
        
        if (map[nx][ny]=='1')
        {
            map[nx][ny]='2';
            cnt++;
            dfs(nx,ny);
        }
    }
}
