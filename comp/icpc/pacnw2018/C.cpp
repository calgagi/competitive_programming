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

    unordered_map<int,int> m;
    int n, k; cin >> n >> k;
    forn(i, n) {
        int a; cin >> a;
        m[a]++;
    }
    vector<int> a(1, 0);
    for (auto i = m.begin(); i != m.end(); i++)
        a.pb(i->second);

    vector<vector<ll> > dp(m.size()+1, vector<ll>(k+1, 0));
    forn(i, k) dp[i][0] = 1;
    
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < k+1; j++) {
            dp[i][j] = add(mult(a[i], dp[i-1][j-1]), dp[i-1][j]);
        }
    }    
    cout << dp.back().back() << endl;
        
         
    return 0;
}
