#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<pair<int, int>> v;
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        v.push_back({i, num});
    }
    int idx = 0;
    while (true)
    {
        // 터뜨릴 풍선 번호
        cout << v[idx].first << " ";
        
        // 풍선에 적힌 숫자
        int next = v[idx].second;
        
        //그 숫자에 해당하는 풍선
        v.erase(v.begin() + idx);
        
        if (v.empty())
            break;
        if (next> 0)// 양수. 오른쪽으로 움직여야한다면
            idx = (idx + next -1) % v.size();
            
        else
        {//음수. 왼쪽으로 움직여야 한다면
            idx = idx + next;//현재에서 업데이트하고 그 인덱스가
            while (idx < 0) //음수라면
                idx += v.size();
        }
    }
    return 0;
}
