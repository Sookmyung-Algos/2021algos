// 듣보잡 1764

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    string name;
    cin >> n >> m;
    
    vector <string> v1(n);
    vector <string> v;
    
    for(int i=0;i<n;i++){
        cin >> v1[i];
    }
    sort(v1.begin(),v1.end());
    
    for(int i=0;i<m;i++){
        cin >> name;
        if (binary_search(v1.begin(),v1.end(),name)){
            v.push_back(name);
        }
    }
    sort(v.begin(),v.end());
    
    cout << v.size() << '\n';
    for (int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
    return 0;
}
