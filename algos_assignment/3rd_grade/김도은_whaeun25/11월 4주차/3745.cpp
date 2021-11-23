#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() {
    while(cin >> n){
        v.clear();
        
        for(int i = 1; i <= n; i++){
            int cost;
            cin >> cost;
            
            if(v.empty() || v.back() < cost){
                v.push_back(cost);
            }
            else{
                int index = lower_bound(v.begin(), v.end(), cost) - v.begin();
                v[index] = cost;
            }
        }
        cout << v.size() << "\n";
    }
}
