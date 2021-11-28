#include <iostream>
using namespace std;

int main() {
    int n, a[1001],d[1001]={0,};
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]){
                if(d[i] < d[j]) {
                    d[i] = d[j];
                }
            }
        }
        d[i]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ans < d[i]) {
            ans = d[i];
        }
    }
    cout<<ans;
}
