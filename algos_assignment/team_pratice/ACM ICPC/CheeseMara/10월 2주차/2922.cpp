#include <iostream>
#include <cstring>
using namespace std; 
 
char word[101];

long long makeword(int idx){
    while(true){
        if (word[idx] == '\0'){
            int c = 0, v = 0;
            bool l = false;
            for (int i = 0; i < idx; i++){
                if (word[i] == 'C' || word[i] == 'L'){
                    c++;
                    v = 0;
                    if (word[i] == 'L') 
                        l = true;
                }
                else if (word[i] == 'V'){
                    v++;
                    c = 0;
                }
                if (c >= 3 || v >= 3)
                    return 0LL;
            }
            if (l == true)
                return 1LL;
            else 
                return 0LL;
        }
        if (word[idx] == '_')
        {
            long long result = 0LL;
            word[idx] = 'C'; result += 20LL * makeword(idx + 1);
            word[idx] = 'V'; result += 5LL * makeword(idx + 1);
            word[idx] = 'L'; result += makeword(idx + 1);
            word[idx] = '_';
            return result;
        }
        idx++;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> word;
    for (int i = 0; i < strlen(word); i++){
        char c = word[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            word[i] = 'V';
        else if (c != '_' && c != 'L')
            word[i] = 'C';
    }
    cout << makeword(0) << "\n";
}
