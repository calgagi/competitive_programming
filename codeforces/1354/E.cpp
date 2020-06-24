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

int n, m;
int n1, n2, n3;
vector<vector<int>> adj;
vector<int> color;
bool invalid = 0;
vector<vector<int>> cc;

int change(int a) {
    return (a == 0 ? 1 : 0);
}

void dfs(int u, int c, vector<int>& cur) {
    if (invalid || (color[u] != -1 && color[u] != c)) {
        invalid = 1;
        return;
    } 
    if (color[u] != -1) {
        return;
    }
    color[u] = c;
    cur.push_back(u);
    for (int& v : adj[u]) {
        dfs(v, change(c), cur);
    }
    return;
}

void solve() {
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    color.assign(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            cc.push_back(vector<int>());
            dfs(i, 0, cc[cc.size()-1]);
        }
    }

    if (invalid) {
        cout << "NO" << endl;
        return;
    }

    // at this point, we have a bunch of bipartite connected components
    // need to find correct combination to equal n2

    int num_cc = cc.size();

    vector<vector<int>> cnt(num_cc, vector<int>(2, 0));
    for (int i = 0; i < num_cc; i++) {
        for (int v : cc[i]) {
            cnt[i][color[v]]++;
        }
    }
    
    // use knapsack
    vector<vector<int>> dp(num_cc+1, vector<int>(n2+1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < num_cc; i++) {
        for (int j = 0; j <= n2; j++) {
            if (dp[i][j] != -1) {
                if (j + cnt[i][0] <= n2) {
                    dp[i+1][j + cnt[i][0]] = 0;
                } 
                if (j + cnt[i][1] <= n2) {
                    dp[i+1][j + cnt[i][1]] = 1;
                }
            }
        }
    }

    if (dp[num_cc][n2] == -1) {
        cout << "NO" << endl;
        return;
    }

    // backtrack to find answer
    int row = num_cc, col = n2;
    vector<int> ans(n, 0);
    while (row > 0) {
        for (int& x : cc[row-1]) {
            if (dp[row][col] == color[x]) {
                ans[x] = 2;
            }
        }
        col -= cnt[row-1][dp[row][col]];
        row -= 1;
    }

    // print
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (n1 && ans[i] != 2) {
            ans[i] = 1;
            n1--;
        } else if (n3 && ans[i] != 2) {
            ans[i] = 3;
            n3--;
        }
        cout << ans[i];
    }
    cout << endl;

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
