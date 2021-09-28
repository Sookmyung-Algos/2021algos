#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t>0){
        cin >> n;
        string name, type;
        vector<pair<string, int> > cnt; 
        for(int i=0;i<n;i++){
            cin >> name >> type;
            int j;
            for(j=0;j<cnt.size();j++){
                if(cnt[j].first==type){
                    cnt[j].second+=1;
                    break;
                }
            }
            if(j>=cnt.size())
                cnt.push_back(make_pair(type,1));
        }
        int ans=1;
        for(int i=0;i<cnt.size();i++)
            ans*=cnt[i].second+1;
        cout << ans-1 << "\n";
        t--;
    }
}
