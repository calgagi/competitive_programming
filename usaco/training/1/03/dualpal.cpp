/*
ID: calgagi1
LANG: C++
TASK: dualpal
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


string convert_to_base(int base, int num) {
    string r = "";
    int ex = base;
    while (ex <= num) ex *= base;
    ex /= base;
    while (ex != 0) {
        r += '0' + num / ex;
        num %= ex;
        ex /= base;
    }
    return r;
}

bool is_palindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) 
            return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("dualpal.in", "r", stdin), *OUT = freopen("dualpal.out", "w", stdout); 

    int s, n;
    cin >> n >> s;

    s++;
    int counter = 0;
    while (counter < n) {
        int found = 0;
        for (int i = 2; i <= 10; i++) {
            string b = convert_to_base(i, s);
            if (is_palindrome(b))
               found++;
        }
        if (found >= 2) {
            cout << s << endl;
            counter++;
        }
        s++;
    }

    return 0;
}
