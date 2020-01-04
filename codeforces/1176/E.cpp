// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> chosen;


void dfs(int cur, int chose) {
    chosen[cur] = chose;
    for (int i = 0; i < (int) g[cur].size(); i++) {
        if (!chosen[g[cur][i]]) {
            dfs(g[cur][i], (chose==1?-1:1));
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    g.assign(n, vector<int>());
    chosen.assign(n, 0);
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(0, 1); 

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (chosen[i] == 1)
            count++;
    }

    int new_count = min(count, n-count);
    cout << new_count << endl;
    for (int i = 0; i < n; i++) {
        if (new_count != count)
            chosen[i] = (chosen[i]==1?-1:1);
        if (chosen[i] == 1)
            cout << i+1 << " ";
    } 
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
