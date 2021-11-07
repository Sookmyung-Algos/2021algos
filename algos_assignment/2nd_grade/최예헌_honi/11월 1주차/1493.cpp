//분할정복
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector <pair<int,int>> arr;
int cnt=0;
bool flag=true;

void sol(int l,int w,int h){
    if (!flag)
        return;
    
    if (l==0||w==0||h==0)
        return;
    
    for (int i=0;i<n;i++){
        if (arr[i].second>0){
            if (arr[i].first<=l && arr[i].first<=w && arr[i].first<=h){
                arr[i].second--;
                cnt++;
                
                sol(arr[i].first,w-arr[i].first,arr[i].first);
                sol(l-arr[i].first,w,arr[i].first);
                sol(l,w,h-arr[i].first);
                return;
            }
        }
    }
    
    flag=false;
}

int main(){
    int length,width,height;
    int a,b;
    
    cin>>length>>width>>height;
    cin>>n;
    
    for (int i=0;i<n;i++){
        cin>>a>>b;
        int temp=pow(2,a);
        arr.push_back({temp,b});
    }
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    
    sol(length,width,height);
    
    if (flag)
        cout<<cnt;
    else
        cout<<"-1";
}
