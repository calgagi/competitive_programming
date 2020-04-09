/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const int M = -1e9+7;
vector<vector<int>> g;
vector<vector<int>> dp;

int dfs(int u, bool c, int par) {
    if (dp[u][c] != M) {
        return dp[u][c];
    }
    int free = 0;
    for (auto& v : g[u]) {
        if (v != par) {
            free += dfs(v, 1, u);
        }
    }
    if (c) {
        for (auto& v : g[u]) {
            if (v != par) {
                dp[u][c] = max(dp[u][c], 1+free+dfs(v,0,u)-dfs(v,1,u));
            }
        }
    }
    dp[u][c] = max(free, dp[u][c]);
    return dp[u][c];
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    g.resize(n);
    dp.resize(n, vector<int>(2, M));
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans1 = dfs(0, 1, -1); 
    int ans2 = dfs(0, 0, -1);

    /* for (int i = 0; i < n; i++) { */
    /*     cout << dp[i][0] << " "; */
    /* } */
    /* cout << endl; */
    /* for (int i = 0; i < n; i++) { */
    /*     cout << dp[i][1] << " "; */
    /* } */
    /* cout << endl; */

    cout << max(ans1, ans2) << endl;

    return 0;
}
