#include <iostream>
using namespace std;

int n;
int arr[3001][3001];
int a=0,b=0,c=0;
int num[3]={0,};

void solve(int x,int y,int cnt);

int main(){
    int x;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>x;
            if (x==-1)
                arr[i][j]=2;
            else
                arr[i][j]=x;
        }
    }
    solve(0,0,n);
    cout<<num[2]<<'\n'<<num[0]<<'\n'<<num[1];
}


void solve(int x,int y,int cnt){
    if (cnt==1){
        if (arr[x][y]==-1)
            num[2]++;
        else
            num[arr[x][y]]++;
    }
    
    else{
        int temp=arr[x][y];
        int count=0;
        
        for (int i=x;i<x+cnt;i++){
            for (int j=y;j<y+cnt;j++){
                if (arr[i][j]==temp)
                    count++;
                else
                    break;
            }
        }
        
        if (count==(cnt*cnt)){
            if (arr[x][y]==-1)
                num[2]++;
            else
                num[arr[x][y]]++;
        }
            
        else{
            solve(x,y,cnt/3);
            solve(x+cnt/3,y,cnt/3);
            solve(x+cnt/3*2,y,cnt/3);
            solve(x,y+cnt/3,cnt/3);
            solve(x+cnt/3,y+cnt/3,cnt/3);
            solve(x+cnt/3*2,y+cnt/3,cnt/3);
            solve(x,y+cnt/3*2,cnt/3);
            solve(x+cnt/3,y+cnt/3*2,cnt/3);
            solve(x+cnt/3*2,y+cnt/3*2,cnt/3);
        }
    }
}
