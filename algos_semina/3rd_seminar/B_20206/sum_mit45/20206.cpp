#include <iostream>
#include <vector>
using namespace std;

struct map{
    int x;
    int y;
}m[4];

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c;
    int x1,x2,y1,y2;
    vector <int> v[2];
    
    cin>>a>>b>>c;
    cin>>x1>>x2>>y1>>y2;
    m[0].x=x1; m[0].y=y1;
    m[1].x=x2; m[1].y=y1;
    m[2].x=x1; m[2].y=y2;
    m[3].x=x2; m[3].y=y2;
    
    for (int i=0;i<4;i++){
        if (a*m[i].x+b*m[i].y+c<=0){
            v[0].push_back(i);
        }
        
        if (a*m[i].x+b*m[i].y+c>=0){
            v[1].push_back(i);
        }
    }
    
    if (v[0].size()==4 || v[1].size()==4)
        cout<<"Lucky";
    else
        cout<<"Poor";
}
