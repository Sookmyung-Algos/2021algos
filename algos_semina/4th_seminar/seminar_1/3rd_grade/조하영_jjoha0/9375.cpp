#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n;
    string catag, name;

    while (T--)
    {
        map<string, int> ootd;
        cin >> n;
        while (n--)
        {
            cin >> name >> catag;
            // 찾는 key값이 없으면 end 주소를 리턴
            if (ootd.find(catag) == ootd.end())
            {
                ootd.insert({catag, 1});
            }
            else
                ootd[catag]++;
        }

        int ans = 1;
        for (auto i : ootd)
        {
            ans *= (i.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }

    return 0;
}
