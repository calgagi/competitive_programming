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
    bool found = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            s.erase(s.begin()+i);
            found = true;
            break;
        }
    }
    if (!found) {
        s.erase(s.begin());
    }
    cout << s << endl;


    return 0;
}
