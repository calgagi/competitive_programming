/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define f first
#define s second

int n, m, k;
vector<vector<ll>> adj;

const ll MOD = 1e9+7;

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector<vector<ll>> ans(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }

    return ans;
}


void solve() {
    cin >> n >> m >> k;
    adj.assign(n, vector<ll>(n, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = 1;
    }

    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    while (k) {
        if ((k & 1)) {
            ans = mult(ans, adj);
        }
        k >>= 1;
        adj = mult(adj, adj);
    }

    ll num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            num += ans[i][j];
            num %= MOD;
        }
    }

    cout << num << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
