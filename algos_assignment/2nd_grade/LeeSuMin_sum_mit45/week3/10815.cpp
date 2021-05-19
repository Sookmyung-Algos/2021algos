#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    // 시간 초과
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n; // 가지고 있는 카드

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i]; // 카드 숫자 입려

    sort(v.begin(), v.end()); // 작은 수 부터 정렬

    int m;
    cin >> m; // 비교할 카드 개수

    for (int i = 0; i < m; i++){

        int num; // 있는지 확인할 숫자
        cin >> num; 

        int low = 0, high = n- 1;
        bool searched = false;

        // 이분 탐색
        while (low <= high) {
            int mid = (low + high) / 2;

            if (v[mid] == num){ // 같은 값 찾으면
                searched = true; // true로 바꾸기
                break;
            }

            else if (v[mid] < num)
                low = mid + 1;

            else
                high = mid - 1;
        }

        if (!searched) // 없다면
            cout << 0 << " ";

        else // 있다면
            cout << 1 << " ";
    }
    return 0;
}
