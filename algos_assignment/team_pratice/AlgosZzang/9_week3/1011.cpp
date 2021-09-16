#include <iostream>
#include <cmath>
using namespace std;

int x,y;
int ans;

int main(){
    int t;
    cin >> t;
    while(t>0){
        cin >> x >> y;
        int size=sqrt((y-x));
        x=x+size*(size+1)/2;
        ans=size;
        for(int k=size;k>0;k--){
            while(k*(k+1)/2<=y-x){
                x+=k;
                ans++;
            }
        }
        cout << ans << "\n";
        t--;
    }
}
