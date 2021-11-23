#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll countA,countB;
    ll maxA, maxB;
    ll sum=0;
    
    cin>>countA>>countB>>maxA>>maxB;

    if (maxA==0){
        if (maxB>=countB)
            sum+=countB;
        else
            sum+=maxB;
    }
    
    else if (maxB==0){
        if (maxA>=countA)
            sum+=countA;
        else
            sum+=maxA;
    }
    
    else if (countA<countB){
    
        sum+=countA;
        if ((countA+1)*maxB>countB)
            sum+=countB;
        else
            sum+=(countA+1)*maxB;
    }
    
    else{   //countA>=countB
        sum+=countB;
        if ((countB+1)*maxA>countA)
            sum+=countA;
        else
            sum+=(countB+1)*maxA;
    }
    cout<<sum;
}

