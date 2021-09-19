#include <iostream>
using namespace std;
#define MAX 246913

int prime[MAX]={0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime[1]=1;
    for(int i=2;i<MAX;i++){
        if(prime[i]==1) continue;
        for(int j=2;i*j<MAX;j++)
            prime[i*j]=1;
    }
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        int cnt=0;
        for(int i=n+1; i<=2*n;i++){
            if(prime[i]==0) cnt++;
        }
        cout << cnt << "\n";
    }
}
