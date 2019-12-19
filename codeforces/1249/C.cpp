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

vector<ll> p;


void solve() {
    ll n; cin >> n;
    // Greedy?
    ll res = 0, copy = n;
    for (int i = 38; i >= 0 && res < n; i--) {
        if (copy < p[i]/2) continue;
        if (p[i] == copy) {
            res += p[i];
        }
        if (p[i]/2 == copy) {
            res += p[i]/2;
        }
        if (copy < p[i] && copy > p[i]/2) {
            res += p[i];
        }
        if (copy > p[i]) {
            res += p[i];
            copy -= p[i];
        }
    }
        

    cout << res << endl;
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    long q; cin >> q;
    p.resize(39);
    p[0] = 1;
    fore(i, 1, 39) p[i] = (ull) 3 * p[i-1];
    while (q--) solve();

    return 0;
}
