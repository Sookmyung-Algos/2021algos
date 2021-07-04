#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,a,b,c;
    cin >> n;
    vector <int> v;
    cin >> a >> b;
    cin >> c;
    for (int i=0;i<n;i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    
    int price = a;
    int cal = c;
    int per = c/a;
    int best = per;
    for (int i=n-1;i>=0;i--){
        price += b;
        cal += v[i];
        if (best < cal/price) best = cal/price;
    }
    cout << best;
    return 0;
}
