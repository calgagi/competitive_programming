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
    int n; cin >> n;
    vector<string> bin(n);
    forn(i, n) cin >> bin[i];
    bool odd = 0;
    int bads = 0;
    forn(i, n) {
        int a[2] = {0, 0};
        for (auto& c : bin[i])
            a[c - '0']++;
        bool bad = a[0] % 2 == 1; 
        if (bin[i].length() % 2 == 1) {
            odd = true;
            break;
        } else if (bad) {
            bads++;
        }

    }
    if (!odd && bads % 2 == 1) cout << n-1 << endl;
    else cout << n << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int Q; cin >> Q;
    while(Q--) solve();

    return 0;
}
