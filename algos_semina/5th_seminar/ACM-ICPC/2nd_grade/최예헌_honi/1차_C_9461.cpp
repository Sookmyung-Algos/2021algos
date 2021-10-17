#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll arr[101];
    ll t,n;
    
    arr[0]=0;
    arr[1]=arr[2]=arr[3]=1;
    arr[4]=arr[5]=2;
    
    for (int i=6;i<101;i++){
        arr[i]=arr[i-1]+arr[i-5];
    }
    
    cin>>t;
    while (t--){
        cin>>n;
        cout<<arr[n]<<'\n';
    }
}
