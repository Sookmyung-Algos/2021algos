#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> date;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    int N;
    cin >> N;
    
    int a,b,c,d;
    for (int i=0;i<N;i++){
        cin >> a >> b >> c >> d;
        if (a*100+b < 301){
            a=3; b=1;
        }
        if (c*100+d>1130){
            c=12; d=1;
        }
        date.push_back({a*100+b,c*100+d});
    }
    sort(date.begin(),date.end());
    
    int start = 300; int end=301;
    int max=0; int cnt=0;
    for (int i=0;i<N;i++){
        if (date[i].first > start && date[i].first <= end){
            if (max < date[i].second){
                max = date[i].second;
            }
            if (date[i].second == 1201){
                cnt++;
                end=max;
                break;
            }
        } else {
            if (end >= max) break;
            cnt++;
            start = end;
            end = max;
            i = i-1;
        }
    }
    
    if (end==1201) cout << cnt << endl;
    else cout << 0 << endl;
}
