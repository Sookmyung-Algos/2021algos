#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100001

int arr[MAX];
int cnt[MAX];
int result=0;

void hanoi(int k,int to){
    if (k==0)
        return;
    
    if (to != arr[k]){
        hanoi(k-1,6-arr[k]-to);
        result+=cnt[k-1];
        result%=1000000;
    }
    else
        hanoi(k-1,to);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int a,b,c,k;
    
    cnt[0]=1;
    for (int i=1;i<MAX;i++){
        cnt[i]=(cnt[i-1]<<1)%1000000;       //(2^i-1)+1
    }
    
    cin>>n;
    cin>>a>>b>>c;
    while(a--){
        cin>>k;
        arr[k]=1;
    }
    
    while(b--){
        cin>>k;
        arr[k]=2;
    }
    
    while(c--){
        cin>>k;
        arr[k]=3;
    }
    
    result=0;
    hanoi(n-1,arr[n]);
    cout<<arr[n]<<'\n'<<result;
}

