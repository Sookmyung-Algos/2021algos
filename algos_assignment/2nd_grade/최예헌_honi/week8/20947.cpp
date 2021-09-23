#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    string x;
    char arr[2001][2001];
    vector <pair<int,int>> vo;
    vector <pair<int,int>> vx;
    bool visit[2001][2001];
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        for (int j=0;j<n;j++){
            arr[i][j]=x[j];
            
            if (x[j]!='.'){
                if (x[j]=='O')
                    vo.push_back({i,j});
                else if (x[j]=='X')
                    vx.push_back({i,j});
                visit[i][j]=true;
            }
        }
    }
    
    for (int i=0;i<vx.size();i++){      //폭탄 설치 가능
        int tx1=vx[i].first-1;
        int tx2=vx[i].first+1;
        int ty1=vx[i].second-1;
        int ty2=vx[i].second+1;
        
        while (tx1>=0 && !visit[tx1][vx[i].second]){
            arr[tx1][vx[i].second]='B';
            tx1--;
        }
        while (tx2<n && !visit[tx2][vx[i].second]){
            arr[tx2][vx[i].second]='B';
            tx2++;
        }
        while (ty1>=0 && !visit[vx[i].first][ty1]){
            arr[vx[i].first][ty1]='B';
            ty1--;
        }
        while (ty2<n && !visit[vx[i].first][ty2]){
            arr[vx[i].first][ty2]='B';
            ty2++;
        }
    }
    
    for (int i=0;i<vo.size();i++){      //폭탄 설치 불가능
        int tx1=vo[i].first-1;
        int tx2=vo[i].first+1;
        int ty1=vo[i].second-1;
        int ty2=vo[i].second+1;
        
        while (tx1>=0 && !visit[tx1][vo[i].second]){
            arr[tx1][vo[i].second]='.';
            tx1--;
        }
        while (tx2<n && !visit[tx2][vo[i].second]){
            arr[tx2][vo[i].second]='.';
            tx2++;
        }
        while (ty1>=0 && !visit[vo[i].first][ty1]){
            arr[vo[i].first][ty1]='.';
            ty1--;
        }
        while (ty2<n && !visit[vo[i].first][ty2]){
            arr[vo[i].first][ty2]='.';
            ty2++;
        }
    }
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}
