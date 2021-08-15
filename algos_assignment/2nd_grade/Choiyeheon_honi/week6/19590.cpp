#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    vector <long long> v;
    long long n,x;
    long long sum=0;
    
    cin>>n;
    
    for (int i=0;i<n;i++){
        cin>>x;
        sum+=x;
        v.push_back(x);
    }
    
    if (n==1){
        cout<<v[0];
        return 0;
    }
    
    sort(v.begin(),v.end());
    
    if (v[n-1]>(sum-v[n-1]))
        cout<<(2*v[n-1]-sum);
    
    else{
        if (sum%2==0)
            cout<<"0";
    
        else
            cout<<"1";
    }
}
