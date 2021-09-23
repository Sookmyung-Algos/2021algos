#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    vector <ll> arr;
  
    cin>>n;
    while (n%2==0){
        arr.push_back(2);
        n/=2;
    }
    
    ll k=3;
    while (k*k<=n){
        while (n%k==0){
            arr.push_back(k);
            n/=k;
        }
        k+=2;
    }

    if (n>1)
        arr.push_back(n);
    
    ll size=arr.size();
    if (size==1){
        cout<<"-1";
    }
    
    else{
        if (size%2==0){
            for (int i=0;i<size;i+=2)
                cout<<arr[i]*arr[i+1]<<' ';
        }
        
        else{
            for (int i=0;i<size-3;i+=2){
                cout<<arr[i]*arr[i+1]<<' ';
            }
            cout<<arr[size-1]*arr[size-2]*arr[size-3];
        }
    }
}
