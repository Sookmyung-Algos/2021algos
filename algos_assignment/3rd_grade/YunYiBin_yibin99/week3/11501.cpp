#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0){
        int n, maxc=0;
        long long sum=0;
        cin >> n;
        vector<int> cost(n);
        for(int i=0;i<n;i++)
            cin >> cost[i];
        for(int i=n-1;i>=0;i--){
            if(cost[i]>maxc){
                maxc=cost[i];
            }
            else{
                sum+=maxc-cost[i];
            }
        }
        cout << sum << "\n";
        t--;
    }
}
