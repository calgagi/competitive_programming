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

    int n, s; cin >> n >> s;
    int m = INT_MIN;
    forn(i, n) {
        int j; cin >> j;
        m = max(j, m);
    }
    int ans = m*s;
    if (ans % 1000 != 0)
        ans += 1000;
    cout << ans / 1000 << endl;
	

    return 0;
}
