#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int ,int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0, t; i<N; i++){
        cin >> t;
        v.push_back({i, t});
    }
 
    while (!v.empty()){
        cout << v.front().first << ' ';
        int ball = v.front().second;
        v.erase(v.begin());

        if (ball > 0){
            for (int i = 0; i < ball-1; i++){
                v.push_back(v.front());
                v.erase(v.begin());
            }
        }

        else{
            for (int i = 0; i < -ball; i++){
                v.insert(v.begin(), v.back());
                v.pop_back();
            }
        }
    }
}
