#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(){
    int n,w,l;
    int arr[1002];
    
    cin>>n>>w>>l;
    for (int i=0;i<n;i++)
        cin>>arr[i];
    
    int k=0;
    int sum=0;
    int result=w;
    while (true){
        if (k==n)
            break;
        
        if (q.size()>=w){
            result++;
            sum-=q.front();
            q.pop();
        }
        
        if (sum+arr[k]<=l){
            q.push(arr[k]);
            sum+=arr[k];
        }
        else{
            q.push(0);
            k--;
        }
        k++;
    }
    while (!q.empty()){
        q.pop();
        result++;
    }
    cout<<result;
}

