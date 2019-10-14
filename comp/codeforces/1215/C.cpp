// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;    
    string s, t;
    cin >> s >> t;

    vector<int> ab, ba;
    for (int i = 0; i < n; i++) {
        if (t[i] != s[i]) {
            if (s[i] == 'a') {
                ab.pb(i);
            } else if (s[i] == 'b') {
                ba.pb(i);
            }
        }
    }
    if ((ab.size() + ba.size()) % 2 != 0)
        cout << "-1" << endl;
    else {
        int i = 0, j = 0;
        vector<pair<int,int> > r;
        while (i+1 < ab.size()) {
            r.pb({ab[i], ab[i+1]});
            i += 2;
        }
        while (j+1 < ba.size()) {
            r.pb({ba[j], ba[j+1]});
            j += 2;
        }
        if (j < ba.size()) {
            r.pb({ba[j], ba[j]});
            r.pb({ab[i], ba[j]});
        }
        cout << r.size() << endl;
        for (auto z : r)
            cout << z.x+1 << " " << z.y+1 << endl;
    }
             

    return 0;
}
