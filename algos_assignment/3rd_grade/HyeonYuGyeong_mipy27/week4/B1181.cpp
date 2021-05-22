// B1181
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if (a.length()==b.length()) return a<b;
    else return a.length()<b.length();
}

int main() {
    int n;
    string word;
    cin >> n;
    
    vector <string> v;
    for (int i=0;i<n;i++){
        cin >> word;
        v.push_back(word);
    }
    
    sort(v.begin(),v.end(),compare);
    
    string temp;
    for (int i=0;i<n;i++){
        if (temp==v[i]) continue;
        else {
            temp=v[i];
            cout << temp << endl;
        }
    }
    return 0;
}
