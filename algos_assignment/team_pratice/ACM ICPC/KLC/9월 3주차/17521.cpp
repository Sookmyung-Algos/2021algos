#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,w;
    ll arr[15];
    cin>>n>>w;      //요일, 초기 현금
    
    for (int i=0;i<n;i++)
        cin>>arr[i];        //각 가격
    
    ll coin=0;         //가지고 있는 코인
    ll mon=w;
    for (int i=0;i<n-1;i++){
        if (arr[i]<arr[i+1]){
            coin=mon/arr[i];
            mon=mon%arr[i];
            mon+=(arr[i+1]*coin);
        }
    }
    cout<<mon;
}
