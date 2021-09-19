#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,k;
    int arr[101];
    bool visit[101];
    int temp,cnt=0;
    
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    memset(visit,false,sizeof(visit));
    for (int i=0;i<n;i++){
        if (visit[arr[i]])
            continue;
        
        visit[arr[i]]=true;
        temp=arr[i];
        
        for (int j=i+1;j<n;j++){
            if (temp<arr[j] && !visit[arr[j]]){
                visit[arr[j]]=true;
                temp=arr[j];
            }
        }
        cnt++;
    }
    
    if (cnt>k)
        cout<<"NO";
    else
        cout<<"YES";
}
