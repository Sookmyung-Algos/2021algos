#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, n1, n2; 
    vector<pair<int, int>> V;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> n1 >> n2;
        V.push_back({n1, n2});
    }

    sort(V.begin(), V.end());
    for( auto i : V){
        cout<< i.first << " " << i.second << "\n";
    }
    
}
