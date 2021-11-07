#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    string x;
    int cnt=0;
    set <string> name;
    vector <string> result;
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>x;
        name.insert(x);
    }
    
    for (int i=0;i<m;i++){
        cin>>x;
        if (name.find(x)!=name.end()){
            result.push_back(x);
            cnt++;
        }
    }
    sort(result.begin(),result.end());
    cout<<cnt<<'\n';
    for (int i=0;i<result.size();i++)
        cout<<result[i]<<'\n';
}


