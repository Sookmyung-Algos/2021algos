// 5430: AC (Gold 5)
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, n;
    string command;
    string arr;

    cin >> T;
    for (int i = 0; i < T; i++) {
        deque<int> nArr;

        cin >> command;
        cin >> n;
        cin >> arr;
        
        int num = 0;
        for (int i = 0; i < arr.size(); i++) {  // 숫자만 골라서 저장
            if (arr[i] == '[')
                continue;
            else if (arr[i] == ',' || arr[i] == ']') {
                if (num > 0) {
                    nArr.push_back(num);
                    num = 0;
                }
            }
            else if (arr[i] >= '0' && arr[i] <= '9')
                num = 10 * num + arr[i] - '0';
        }

        bool isError = false;
        bool isReverse = false;  // 초기 입력과 비교했을 때 반대인 경우 true

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'R')
                isReverse = isReverse ? false : true;
            else if (command[i] == 'D') {
                if (nArr.empty()) {
                    isError = true;
                    cout << "error\n";
                    break;
                }
                else {
                    if (!isReverse)
                        nArr.pop_front();
                    else
                        nArr.pop_back();
                }
            }
        }
        if (!isError) {
            cout << '[';
            if (!isReverse) {
                while (!nArr.empty()) {
                    cout << nArr.front();
                    nArr.pop_front();
                    if (!nArr.empty())
                        cout << ",";
                }
            }
            else {
                while (!nArr.empty()) {
                    cout << nArr.back();
                    nArr.pop_back();
                    if (!nArr.empty())
                        cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
