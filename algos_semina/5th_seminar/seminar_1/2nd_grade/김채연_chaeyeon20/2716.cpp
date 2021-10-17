#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a;
    getline(cin, a);
    for (int i = 0; i < n; i++) {
       
        char c;
        string str;
        getline(cin, str);
        
        int len = str.size();
        int level = 0, maxlevel = 0;
        for (int j = 0; j < len; j++) {
            if (str[j] == '[') {
                level++;
                if (level > maxlevel) maxlevel = level;
            }
            else level--;
        }
        int result = 1;
        for (int j = 0; j < maxlevel; j++)
            result *= 2;
        cout << result << endl;
    }
}
