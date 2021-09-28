#include <iostream>
using namespace std;

int n;
int arr[129][129];
int w=0,b=0;

void solve(int x,int y,int len);
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cin>>arr[i][j];
    }
    solve(1,1,n);
    cout<<w<<'\n'<<b;
}

void solve(int x,int y,int len){
    bool check=true;
    for (int i=x;i<x+len;i++){
        for (int j=y;j<y+len;j++){
            if (arr[i][j]!=arr[x][y]){
                check=false;
                break;
            }
        }
    }
    
    if (check){
        if (arr[x][y]==0)
            w++;
        else
            b++;
    }
    else{
        solve(x,y,len/2);
        solve(x+len/2,y,len/2);
        solve(x,y+len/2,len/2);
        solve(x+len/2,y+len/2,len/2);
    }
    return;
}
