#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long n,d;
    long long arr[1000001];
    long long amin=INFINITY, bmin=INFINITY;
    long long amax=-INFINITY, bmax=-INFINITY;
    
    cin>>n>>d;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    //x+(i-1)d , x-(i-1)d => 이동거리: arr[i]-(...) => (...)-x
    for (int i=0;i<n;i++){
        if (amin>arr[i]-(i)*d)
            amin=arr[i]-(i)*d;
        if (amax<arr[i]-(i)*d)
            amax=arr[i]-(i)*d;
        
        if (bmin>arr[i]+(i)*d)
            bmin=arr[i]+(i)*d;
        if (bmax<arr[i]+(i)*d)
            bmax=arr[i]+(i)*d;
    }
    
    long double result;     //x=(max+min)/2 => max-x=(max-min)/2
    if (abs(amax-amin)<abs(bmax-bmin)){
        result=(long double)abs(amax-amin)/2;
    }
    
    else{
        result=(long double)abs(bmax-bmin)/2;
    }
    printf("%.1Lf",result);
}
