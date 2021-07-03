#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t,n,m;
    
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m;
        vector <int> vector_a;
        vector <int> vector_b;
        for (int j=0;j<n;j++){
            int a;
            cin >> a;
            vector_a.push_back(a);
        }
        for (int j=0;j<m;j++){
            int b;
            cin >> b;
            vector_b.push_back(b);
        }
        sort(vector_a.begin(),vector_a.end());
        sort(vector_b.begin(),vector_b.end());
        
        int cnt=0;
        for (int j=vector_a.size()-1;j>=0;j--){
            for (int k=vector_b.size()-1;k>=0;k--){
                if (vector_a[j] > vector_b[k]) cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
