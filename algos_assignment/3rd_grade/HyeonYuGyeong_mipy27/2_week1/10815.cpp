#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1;

int arr[500001]={0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N,M,a;
    
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    
    cin >> M;
    for (int i=0;i<M;i++){
        cin >> a;
        
        int s=0, e=N-1;
        bool flag = false;
        while (s <= e){
            int mid =(s+e)/2;
            if (v1[mid] == a){
                flag = true;
                break;
            } else if (v1[mid] < a){
                s = mid+1;
            } else e = mid-1;
        }
        if (flag) cout << 1 << " ";
        else cout << 0 << " ";
    }
}
