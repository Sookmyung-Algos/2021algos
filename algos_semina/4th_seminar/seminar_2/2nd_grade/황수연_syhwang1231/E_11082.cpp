#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    if (s.find('.') == -1) {  // 정수인 경우
        cout << s << "/1";
    }
    else {  // 소수인 경우
        int denominator, numerator;
        int num = stoi(s.substr(0, s.find('.')));  // 정수 부분
        if (s.find('(') == -1) {  // 순환소수가 아닌 경우
            string den = "";
            int decimal = stoi(s.substr(s.find('.') + 1));  // 소숫점 아래 전체
            den += '1';
            for (int i = 0; i < size(s.substr(s.find('.')+1)); i++)
                den += '0';
            denominator = stoi(den);  // 분모
            numerator = decimal;  // 분자
            // 약분
            int gcdN = gcd(denominator, numerator);
            denominator /= gcdN;
            numerator /= gcdN;
        }
        else {  // 순환소수인 경우
            string den = "";
            string dec = "";
            string notCirc = "";
            string circ = "";
            int notCircular = 0;

            if (s.find('.') + 1 != s.find('(')) {  // 순환하지 않는 부분 있을 때
                notCirc = s.substr(s.find('.') + 1, s.find('(') - s.find('.') - 1);
                notCircular = stoi(notCirc);  // 소숫점 아래에서 순환안하는 부분
            }
            circ = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
            dec += notCirc + circ;  // 소숫점 아래 전체
            int decimal = stoi(dec);
            for (int i = 0; i < circ.size(); i++)  // 순환하는 길이만큼 9
                den += '9';
            for (int i = 0; i < notCirc.size(); i++)  // 비순환 길이만큼 0
                den += '0';
            denominator = stoi(den);  // 분모
            numerator = decimal - notCircular;  // 분자
            // 약분
            int gcdN = gcd(denominator, numerator);
            denominator /= gcdN;
            numerator /= gcdN;
        }
        numerator += num * denominator;
        cout << numerator << '/' << denominator;
    }

    return 0;
}
