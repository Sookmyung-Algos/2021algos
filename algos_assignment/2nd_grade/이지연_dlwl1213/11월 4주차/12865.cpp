#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n,k;
int d[100001];  // 가방 용량
int w[101];     // 물건의 무게
int v[101];     // 물건의 가치

void dp(){
    for(int i=1; i<=n; i++){
        for(int j=k; j>=1; j--){
            if(w[i] <= j){
                d[j] = max(d[j], d[j-w[i]] + v[i]);
            }
        }
    }
    
    cout << d[k] << "\n";
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    
    dp();
    
    return 0;
}
