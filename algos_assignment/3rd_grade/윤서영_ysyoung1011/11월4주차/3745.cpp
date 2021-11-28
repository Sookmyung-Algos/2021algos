#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <int> v;

int main() {
    while(cin >> n) {
        v.clear();

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if(v.empty() || v.back() < num) {
                v.push_back(num);
            }
            else {
                int index = lower_bound(v.begin(),v.end(), num) - v.begin();
                v[index] = num;
            }
        }
        cout << v.size() << '\n';
    }
}
