#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int month_arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    string weeks[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month, day;
    int sum = 0;

    cin >> month >> day;

    for (int i=0; i<month; i++) {
        sum += month_arr[i];
    }
    sum += day;
    cout << weeks[sum%7] << '\n';
}
