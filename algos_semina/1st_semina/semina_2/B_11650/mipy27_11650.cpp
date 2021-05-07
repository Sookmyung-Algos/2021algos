#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector <pair<int,int>> arr(n);
    for (int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    
    for (int i=0;i<n;i++){
        cout << arr[i].first << " " << arr[i].second << '\n';
    }
    return 0;
}
