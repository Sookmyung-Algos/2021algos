#include <iostream>
using namespace std;

int ballon[1001];
int order[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ballon[i];
    }
    int d=ballon[1], cnt=1, idx=1;
    ballon[1]=0;
    order[cnt]=1;
    while(cnt<n){
        if(d<0){
            while(d<0){
                idx-=1;
                if(idx<=0)
                    idx=n;
                if(ballon[idx]!=0)
                    d+=1;
            }
        }
        else{
            while(d>0){
                idx+=1;
                if(idx>n) idx=1;         
                if(ballon[idx]!=0)
                    d-=1;
            }
        }
        d=ballon[idx];
        ballon[idx]=0;
        cnt+=1;
        order[cnt]=idx;
    }
    for(int i=1;i<=n;i++) cout << order[i] << " ";
}
