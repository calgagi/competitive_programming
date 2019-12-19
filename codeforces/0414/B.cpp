// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
template<class T>
inline std::ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii) { os << " " << *ii; } os << "]"; return os; }
template<class T1, class T2>
inline std::ostream& operator<<(ostream& os, const pair<T1, T2>& p) { os << "["; os << p.F << "," << p.S; os << "]"; return os; }

int MOD = 1e9 + 7;

int add(ll a, ll b) {
    return (a + b) % MOD;
}

int mult(ll a, ll b) {
    return (a * 1LL * b) % MOD;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n, k; cin >> n >> k;
    vector<vector<int>> dp(k, vector<int>(n+1, 0));
    fore(i, 1, n+1) dp[0][i] = 1;
    // DP?
    // dp[i][j]. i = Current number of steps, j = Current number
    // dp[i][j] = sum of all dp[i-1][d] where d divides j
    vector<vector<int>> div(n+1);
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j <= sqrt(i); j++)
            if (i % j == 0) { 
                div[i].push_back(j);
                if (j != i / j)
                    div[i].push_back(i / j);
            }
    }
    
    fore(i, 1, k) {
        fore(j, 1, n+1) {
            for (auto& d : div[j]){
                dp[i][j] = add(dp[i][j], dp[i-1][d]);
            }
        } 
    }
    
    int res = 0;
    fore(i, 1, n+1) res = add(dp[k-1][i], res);
    cout << res << endl;

    return 0;
}
