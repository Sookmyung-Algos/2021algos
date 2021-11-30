#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    int n, cost;
    while(cin >> n){
        v.clear();
        for(int i=0;i<n;i++){
            cin >> cost;
            if(v.empty() || cost>v.back()) v.push_back(cost);
            else{
                int j;
                for(j=v.size()-1;j>=0;j--){
                    if(v[j]<cost) break;
                }
                v[j+1]=cost;
            }
        }
        cout << v.size() << "\n";
    }
}
