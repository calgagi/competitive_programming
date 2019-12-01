// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
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
	
    int n; cin >> n;
    vector<int> m(n);
    forn(i,n) cin >> m[i];
    vector<int> dp(n, 0);
    int seen = m[0];
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        if (m[i-1] > m[i])
            dp[i] = dp[i-1];
        else if (m[i] < seen) {
            dp[i] = dp[i-1]+1;
            seen = m[i];
        } else {
            dp[i] = dp[i-1];
        }
        seen = max(m[i], seen);
    }

    cout << dp[n-1] << endl;
    return 0;
}
