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
ll MOD = 998244353;

int add(long a, long b) {
    return (a + b) % MOD;
} 

int mult(long a, long b) {
    return (a * 1LL * b) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    unordered_map<int,int> c;
    int x;
    forn(i, n) {
        cin >> x;
        c[x]++;
    }
    n = c.size();
    vector<vector<int> > dp(k+1, vector<int>(n+1, 0));
    forn(i, n+1) dp[0][i] = 1;
    vector<int> v;
    for (auto& it : c) v.pb(it.second);
    fore(i, 1, k+1)
        fore(j, 1, n+1)
            dp[i][j] = add(mult(dp[i-1][j-1], v[j-1]), dp[i][j-1]);
    cout << dp.back().back() << endl;	

    return 0;
}
