#include <string>
using namespace std;

bool CompareWord(string a, string b) {
    if (a.length() == b.length()) return a < b;
    else  return a.length() < b.length();
}

int main() {
    int N;
    string str;
    vector<string> word;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        word.push_back(temp);
    }
    sort(word.begin(), word.end(), CompareWord); //CompareWord 함수를 기준으로 정렬
    for (int i = 0; i < word.size(); i++) {
        if (word[i] != word[i + 1]) cout << word[i] << "\n";
    }
    return 0;
}
