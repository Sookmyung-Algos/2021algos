#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>


using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, pos;
    int l_arr[26] = {0, };
    bool used[100100];
    map<char, vector<int>> m;
    string answer_h, answer_s, letters;
    
    cin >> N >> letters;
    int s_ptr = letters.size(), h_ptr = 0;
    
    for (int i = 0; i < N; i++) {
        l_arr[letters[i] - 'a']++;
        m[letters[i]].push_back(i);
        used[i] = false;
    }
    
    while (h_ptr < N) {
        --s_ptr;
        while (used[s_ptr] || l_arr[letters[s_ptr] - 'a'] <= 0) --s_ptr;
        
        answer_s += letters[s_ptr];
        l_arr[letters[s_ptr] - 'a']--;
        m[letters[s_ptr]].pop_back();
        used[s_ptr] = true;
        
        h_ptr++;
        
        char selected = '\0';
        for (int i = 0; i < 26; i++) {
            if (l_arr[i] > 0) {
                selected = i + 'a';
                l_arr[i]--;
                h_ptr++;
                break;
            }
        }
        
        answer_h += selected;
        pos = m[selected].back();
        used[pos] = true;
        m[selected].pop_back();
    }
    
    if (answer_h >= answer_s) cout << "NE" << '\n';
    else cout << "DA" << '\n';
    
    cout << answer_h << '\n';
    return 0;
}
