#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int>m;
    for (int i = 0; i < participant.size(); i++) {
        if (!m.insert({ participant[i],1 }).second)//중복되면
            m[participant[i]]++;//value 증가
    }
    for (string i : completion) {
        m[i]--;
    }
    for (string i : participant) {
        if (m[i] == 1)answer = i;
    }
    return answer;
}

int main() {
    vector<string> participant, completion;
    int n,n2;
    cin >> n;
    n2 = n - 1;
    while (n--) {
        string name;
        cin >> name;
        participant.push_back(name);
    }
    while (n2--) {
        string name;
        cin >> name;
        completion.push_back(name);
    }
    cout<<solution(participant, completion);
    return 0;
}
