//좌표압축: 해결못함
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int n;
    int x,y;
    vector <pair<int,int>> arr;
    vector <int> vx;
    vector <int> vy;
    int cnt=0;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        arr.push_back({x,y});
        vx.push_back(x);
        vy.push_back(y);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    
    map <int,int> mx;       //x 좌표압축
    for (int i=0;i<vx.size();i++){
        mx[vx[i]]=i;
    }
    
    sort(vy.begin(),vy.end());
    vy.erase(unique(vy.begin(),vy.end()),vy.end());
    
    map <int,int> my;       // y좌표압축
    for (int i=0;i<vy.size();i++){
        my[vy[i]]=i;
    }
    
    for (int i=0;i<arr.size();i++){
        arr[i].first=mx[arr[i].first];
        arr[i].second=my[arr[i].second];
    }
    
    sort(arr.begin(),arr.end());
    
    int y1,y2;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i].first==arr[j].first){
                y1=arr[i].second;
                y2=arr[j].second;
            }
            else
                break;
            
            for (int k=j+1;k<n;k++){
                if (arr[i].first==arr[k].first || y1!=arr[k].second)
                    continue;
                
                for (int t=k+1;t<n;t++){
                    if (arr[k].first==arr[t].first){
                        if (y2==arr[t].second){
                            cnt++;
                        }
                    }
                    else
                        break;
                }
            }
        }
    }
    cout<<cnt;
}


