#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool cmp(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }
    if (s1.length() < s2.length()) {
        return true;
    }
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) continue;
        if (s1[i] > s2[i])
            return false;
        if (s1[i] < s2[i])
            return true;
    }
    return false;
}
string delHeadingZero(string str) {
    int notZeroIdx = -1;
    string ret = "";
    for (int i = 0; i < str.length(); i++) {
        if (notZeroIdx == -1 && str[i] != '0') {
            notZeroIdx = i;
            break;
        }
    }
    for (int i = notZeroIdx; i < str.length(); i++) {
        ret += str[i];
    }
    if (ret == "") ret = "0";
    return ret;
}
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    string str;
    string digit = "";
    vector<string> answers;
    bool is_prev_digit = false;
    cin >> N;
    for (int ai = 0; ai < N; ai++) {
        cin >> str;
        for (int bi = 0; bi < str.length(); bi++) {
            if (isdigit(str[bi])) {
            digit += str[bi];
            }
            if (!isdigit(str[bi]) && is_prev_digit) {
                answers.push_back(delHeadingZero(digit));
                digit.clear();
            }
            is_prev_digit = isdigit(str[bi]);
        }
        if (digit.size() != 0) {
            answers.push_back(delHeadingZero(digit));
            digit = "";
        }

        is_prev_digit = false;
    }
    sort(answers.begin(), answers.end(), cmp);

    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i] << '\n';
    }

    return 0;
}
