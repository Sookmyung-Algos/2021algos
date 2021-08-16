#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<float>arr;
    int front,back,n;
    cin >> n;
    front = 0, back = n - 1;
    while (n--) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    while (front < back) {
        arr[back] += arr[front++] / 2;
    }
    cout << arr[back] << '\n';
    return 0;
}
