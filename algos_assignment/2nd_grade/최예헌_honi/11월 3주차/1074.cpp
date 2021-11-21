#include <iostream>
#include <vector>
using namespace std;

void sol(int x,int y,int n);
int n,r,c;
int num=0;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int temp=1;
    cin>>n>>r>>c;
    while (n--){
        temp*=2;
    }
    sol(0,0,temp);
}

void sol(int x,int y,int n){
    if (x==r && y==c){
        cout<<num;
        exit(0);
    }
    
    if (r<x+n && c<y+n){
        sol(x,y,n/2);
        sol(x,y+n/2,n/2);
        sol(x+n/2,y,n/2);
        sol(x+n/2,y+n/2,n/2);
    }
    else
        num+=n*n;
}

