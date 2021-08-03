//AC
//BOJ 20206 푸앙이가 길을 건너간 이유
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    int cnt = 0;
    double A, B, C;
    cin >> A >> B >> C;
    double x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    double a = (-(x1 * A) - C)/B; 
    double b = -(x2 * A + C)/B;
    double c = -(y1 * B + C)/A;
    double d = -(y2 * B + C)/A;
    if (y1 < y2) {
        if (a > y1 && a < y2)   cnt++;
        if (b > y1 && b < y2)   cnt++;
    }
    else {
        if(a > y2 && a < y1)    cnt++;
        if(b > y2 && b < y1)    cnt++;
    }
    if(x1 > x2) {
        if(c > x2 && c < x1)    cnt++;
        if(d > x2 && d < x1)    cnt++;
    }
    else {
        if(c > x1 && c < x2)    cnt++;
        if(d > x1 && d < x2)    cnt++;
    }
    if(cnt >=2)     cout<<"Poor";
    else if(cnt < 2)    cout << "Lucky";
    return 0;
}