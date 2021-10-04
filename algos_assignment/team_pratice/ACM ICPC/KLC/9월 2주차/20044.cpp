#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,x;
    vector <int> arr;
    int result=INFINITY;
    
    cin>>n;
    for (int i=0;i<2*n;i++){
        cin>>x;
        arr.push_back(x);
    }
    
    sort(arr.begin(),arr.end());
    
    for (int i=0;i<n;i++)
        result=min(result,arr[i]+arr[(2*n-1)-i]);
    cout<<result;
}
