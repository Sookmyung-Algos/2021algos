#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    
    int x1, x2, y1, y2;
    vector<pair<int,int>> coordinate;
    cin >> x1 >> x2 >> y1 >> y2;
    
    coordinate.push_back({x1, y1});
    coordinate.push_back({x1, y2});
    coordinate.push_back({x2, y1});
    coordinate.push_back({x2, y2});
    
    int cnt1=0, cnt2 = 0;
    for (int i = 0; i < coordinate.size();i++)
    {
        if (coordinate[i].first * A + coordinate[i].second * B + C < 0)
            cnt1++;
        else if (coordinate[i].first * A + coordinate[i].second * B + C > 0)
            cnt2++;
    }
    if (cnt1 > 0 && cnt2 > 0)
        cout << "Poor";
    else
        cout << "Lucky";
        
    return 0;
}
