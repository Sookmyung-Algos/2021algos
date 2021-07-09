#include <iostream>
#include <stack>

using namespace std;

bool check(string string){
    stack <char> stack;
    
    for (int i=0;i<string.size();i++){
        char c = string[i];
        if (c=='('){
            stack.push(c);
        } else { // ')'면
            if (!stack.empty()) stack.pop();
            else return false;
        }
    }
    return stack.empty();
}

int main() {
    int T;
    cin >> T;
    
    string string="";
    for (int i=0;i<T;i++){
        cin >> string;
        if (check(string)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
