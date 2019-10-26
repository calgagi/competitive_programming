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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    ll n; cin >> n;
    ll m, mi;
    mi = -1;
    m = INT_MIN;
    forn(i,n) {
        int t; cin >> t;
        if (t >= m) {
            m = t;
            mi = i+1;
        } 
    }
    ll res = n*m;
    res -= (n - mi);
    cout << res << endl;
    return 0;
}
