#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int alr, will, dis;
int min_num = 0;

vector<int> v;

void start() {
    sort(v.begin(), v.end());

    int left = 0; int right = dis;

    while (left <= right) {
        int mid = (left + right) / 2;
        int rest = 0;

        for (int i = 1; i < (int)v.size(); i++) {
            if ((v.at(i) - v.at(i - 1)) % mid == 0) {
                rest += (v.at(i) - v.at(i - 1) - 1) / mid;
            }
            else {
                rest += (v.at(i) - v.at(i - 1)) / mid;
            }
        }
        if (rest > will) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    cout << left << '\n';
}

int main() {
    cin >> alr >> will >> dis;
    v.push_back(0);

    for (int i = 0; i < alr; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    v.push_back(dis);
    start();

    return 0;
}
