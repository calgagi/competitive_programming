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
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

void solve() {
    int garbage; cin >> garbage;
    string s; cin >> s;
    forn(i, s.length()) {
        if (s[i] == '8' && s.length()-i >= 11) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int Q; cin >> Q;
    while (Q--) solve();

    return 0;
}
