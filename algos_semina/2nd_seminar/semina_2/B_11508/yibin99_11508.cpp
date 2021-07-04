#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sum=0;
    cin >> n;
    int cost[n];
    for(int i=0;i<n;i++){
        cin >> cost[i];
        sum+=cost[i];
    }        
    sort(cost, cost+n);
    int group = n/3;
    for(int i=1;i<=group;i++){
        sum-=cost[n-i*3];
    }
    cout << sum;
}
