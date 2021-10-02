#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n,x;
    vector <int> arr1;
    vector <int> arr2;
    int result=1,result1=0,result2=0;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        if (n==2){
            result*=x;
        }
        
        if (x>=0)
            arr1.push_back(x);
        else
            arr2.push_back(x);
    }
    
    if (n==2){
        cout<<result;
        return 0;
    }
    
    sort(arr1.begin(),arr1.end(),greater<int>());
    sort(arr2.begin(),arr2.end());
    
    if (arr1.size()>=3 && arr1[0]*arr1[1]*arr1[2]>arr1[0]*arr1[1])
        result1=arr1[0]*arr1[1]*arr1[2];
    else if (arr1.size()>=2)
        result1=arr1[0]*arr1[1];
    
    if (arr2.size()>=2 && arr1.size()>0 && arr2[0]*arr2[1]*arr1[0]>arr2[0]*arr2[1])
        result2=arr2[0]*arr2[1]*arr1[0];
    else if (arr2.size()>=2)
        result2=arr2[0]*arr2[1];
    
    cout<<max(result1,result2);
}

