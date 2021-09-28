#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    int z;
    while(y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int maxx(int a, int b){
    return a*b/gcd(a,b);
}
int main(){
	vector<int>v;
    for(int i=0; i<5; i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    int minn=v[0]*v[1]*v[2];
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            for(int k=j+1; k<5; k++){
                int hi=maxx(v[i],v[j]);
                hi=maxx(hi,v[k]);
                if(minn>hi){
                    minn=hi;
                }
            }
        }
    }
    cout<<minn<<endl;
}
