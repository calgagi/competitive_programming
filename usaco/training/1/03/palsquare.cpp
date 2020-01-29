/*
ID: calgagi1
LANG: C++
TASK: palsquare
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

vector<char> m;

string convert_to_base(int base, int num) {
    int ex = base;
    while (ex <= num) ex *= base;
    ex /= base;
    string r = "";
    while (ex != 0) {
        r += m[num / ex];
        num %= ex;
        ex /= base;
    }
    return r;
}

bool is_palindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i])
            return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("palsquare.in", "r", stdin), *OUT = freopen("palsquare.out", "w", stdout); 

    int b; 
    cin >> b;

    for (int i = 0; i < b; i++) {
        m.push_back((i<=9?'0'+i:'A'+i-10));
    }
        
    for (int i = 1; i <= 300; i++) {
        string s = convert_to_base(b, i*i);
        if (is_palindrome(s)) {
            cout << convert_to_base(b, i) << " " << s << endl;
        }
    } 

    return 0;
}
