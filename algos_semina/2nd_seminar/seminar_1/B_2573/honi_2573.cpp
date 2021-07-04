#include <iostream>
#include <cstring>

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int arr[300][300];
int temp[300][300];
bool visit[300][300];
int N,M;

void dfs(int y,int x){
    visit[y][x]=true;
    for (int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        if (ny<0||nx<0||ny>=N||nx>=M)
            continue;
        if (arr[ny][nx]>0 && !visit[ny][nx])        //방문하지 않은 칸 방문
            dfs(ny,nx);
    }
}

void imelt(){               //빙산 녹이는 함수
    
    for (int y=0;y<N;y++){
        for (int x=0;x<M;x++)
            temp[y][x]=arr[y][x];
    }
    
    for (int y=0;y<N;y++){
        for (int x=0;x<M;x++){
            int count=0;            //주변에 있는 바다칸 수
            if (temp[y][x]>0){
                for (int k=0;k<4;k++){
                    int ny=y+dy[k];
                    int nx=x+dx[k];
                    if (temp[ny][nx]==0)
                        count++;
                }
                arr[y][x]-=count;       //바다로 녹은 각 칸의 높이
                if (arr[y][x]<0)        //높이가 음수이면 0으로
                    arr[y][x]=0;
            }
        }
    }
}

int main(){
    int result,num,year;
    cin>>N>>M;
    for (int y=0;y<N;y++){
        for (int x=0;x<M;x++)
            cin>>arr[y][x];
    }
    
    while (1){
        memset(visit,false,sizeof(visit));
        memset(temp,0,sizeof(temp));
        result=0;
        num=0;
        
        for (int y=0;y<N;y++){
            for (int x=0;x<M;x++){
                if (arr[y][x]!=0 && !visit[y][x]){
                    dfs(y,x);
                    num++;              //빙산 덩어리 수
                    if (num==2){
                        result=1;
                        break;
                    }
                }
            }
        }
        
        if (result==1){         //빙산이 분리되는 최초 시간(년)
            cout<<year;
            break;
        }
        if (num==0){            //다 녹을 때까지 분리되지 않은 경우
            cout<<"0";
            break;
        }
        imelt();
        year++;
    }
    return 0;
}
