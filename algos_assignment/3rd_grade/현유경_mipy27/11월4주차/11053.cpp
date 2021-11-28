//11053 가장 긴 증가하는 부분 수열

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    int a[1001]={0,};
    int d[1001]={0,};
    
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> a[i];
    }
    
    for (int i=0;i<N;i++){
        for (int j=0;j<i;j++){
            if (a[j] < a[i]){
                if (d[i] < d[j]){
                    d[i] = d[j];
                }
            }
        }
        d[i]++;
    }
    
    int ans=0;
    for (int i=0;i<N;i++){
        if (ans < d[i]){
            ans = d[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
