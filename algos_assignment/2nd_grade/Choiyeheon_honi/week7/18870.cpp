#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,x;
    cin>>n;
    vector <ll> arr1(n);
    vector <ll> arr2(n);
    for (int i=0;i<n;i++){
        cin>>x;
        arr1[i]=arr2[i]=x;
    }
    sort(arr1.begin(),arr1.end());
    arr1.erase(unique(arr1.begin(),arr1.end()),arr1.end());
    
    map <ll,ll> map;
    for (int i=0;i<arr1.size();i++){
        map[arr1[i]]=i;
    }
    
    for (int i=0;i<n;i++){
        arr2[i]=map[arr2[i]];
        cout<<arr2[i]<<' ';
    }
}
