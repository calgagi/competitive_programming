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
    int both = 0;
    bool ab = false;
    bool ba = false;
    for (int i = 0; i < s.size()-1; i++) {
        if (i+2 < s.size() && ((s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'A') || (s[i] == 'B' && s[i+1] == 'A' && s[i+2] == 'B'))) {
            both++;
            i += 2;
        } else if (s[i] == 'B' && s[i+1] == 'A') {
            ba = true;
            i += 1;
        } else if (s[i] == 'A' && s[i+1] == 'B') {
            ab = true;
            i += 1;
        }
    }
    int r = (both + ab + ba);
    if (r >= 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
