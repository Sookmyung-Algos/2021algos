#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n,temp,cnt=0,num,tnum;
    queue <int> q;

    cin >> n;
    
    q.push(n);
    num=1;
    while (1) {
        tnum=0;
        while (num--){
            temp=q.front();
            q.pop();
            
            if (temp==1){
                cout<<cnt;
                return 0;
            }
            
            if (temp%3==0){
                q.push(temp/3);
                tnum++;
            }
            
            if (temp%2==0){
                q.push(temp/2);
                tnum++;
            }
            
            q.push(temp-1);
            tnum++;
        }
        num=tnum;
        cnt++;
    }
}
