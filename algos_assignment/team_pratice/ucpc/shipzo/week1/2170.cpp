#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> line;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x, y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        line.push_back(make_pair(x,y));
    }
    sort(line.begin(), line.end());
    int from=line[0].first, to=line[0].second;
    int sum=0;
    for(int i=1;i<n;i++){
        if(line[i].first<=to){
            if(line[i].second>to)
                to=line[i].second;
        }
        else{
            sum+=to-from;
            from=line[i].first;
            to=line[i].second;
        }
    }
    sum+=to-from;
    cout << sum;
}
