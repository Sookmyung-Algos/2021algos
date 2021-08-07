#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    vector <pair<int, int>> v;
    int date[366]={0,};
    vector <int> d;
    int num[365]={0,};
    int sum=0;
    int n;
    
    cin>>n;
    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end());

    for (int i=0;i<n;i++){
        for (int j=v[i].first;j<=v[i].second;j++)
            date[j]++;
    }
    
    for (int i=v[0].first;i<=v[n-1].second;i++){
        if (date[i]==0)
            d.push_back(i);
    }
    
    int k=0;
    for (int i=0;i<d.size();i++){
        int maxx=0,s=366,e=0;
        for (;v[k].second<d[i];k++){
            if (s>v[k].first)
                s=v[k].first;
            if (e<v[k].second)
                e=v[k].second;
            
            for (int j=v[k].first;j<=v[k].second;j++){
                num[j]++;
                if (num[j]>maxx)
                    maxx=num[j];
            }
        }
        sum+=(e-s+1)*maxx;
    }
    
    if (k<=n-1){
        int maxx=0,s=366,e=0;
        for (;k<n;k++){
            if (s>v[k].first)
                s=v[k].first;
            if (e<v[k].second)
                e=v[k].second;
            
            for (int j=v[k].first;j<=v[k].second;j++){
                num[j]++;
                if (num[j]>maxx)
                    maxx=num[j];
            }
        }
        sum+=(e-s+1)*maxx;
    }
    cout<<sum;
    return 0;
}
