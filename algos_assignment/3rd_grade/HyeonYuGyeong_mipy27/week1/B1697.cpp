#include <iostream>
#include <queue>
using namespace std;

int n,k;
bool v[100001] = {false};
bool t;
queue <int> q;

int main() {
    cin >> n >> k;
    q.push(n);
    
    int cnt,seg=1,ans=0;
    while (!q.empty()){
        cnt=0;
        t = false;
        for (int i=0;i<seg;i++){
            int x = q.front();
            q.pop();
            
            if (x==k){
                cout << ans << '\n';
                return 0;
            }
            v[x]=true;
            if (x+1 <= 100000 && !v[x+1]){
                q.push(x+1);
                t = true;
                cnt++;
            }
            if (x-1 >= 0 && !v[x-1]) {
                q.push(x-1);
                t = true;
                cnt++;
            }
            if (2*x <= 100000 && !v[2*x]){
                q.push(2*x);
                t = true;
                cnt++;
            }
        }
        seg=cnt;
        if (t) ans++;
    }
    cout << ans << '\n';
    return 0;
}
