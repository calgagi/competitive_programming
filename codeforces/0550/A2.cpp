// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    string s; cin >> s;

    bool ab = false, ba = false;

    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && !ab) {
            i += 1;
            ab = true;
        }
        else if (s[i] == 'B' && s[i+1] == 'A' && ab) {
            i += 1;
            ba = true;
        }
    }
    int r = ab + ba;
    if (r >= 2) {
        cout << "YES" << endl;
        return 0;
    }
    ab = false, ba = false;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == 'B' && s[i+1] == 'A' && !ab) {
            i += 1;
            ab = true;
        }
        else if (s[i] == 'A' && s[i+1] == 'B' && ab) {
            i += 1;
            ba = true;
        }
    }
    r = ab + ba;
    if (r >= 2) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
