// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

vector<long long> gas;
vector<vector<pair<int,int>>> graph;
vector<long long> dp;
int n;
long long ans = INT_MIN;


void dfs(int cur, int parent) {
    dp[cur] = gas[cur];
    long long mx1 = INT_MIN, mx2 = INT_MIN;
    for (auto& p : graph[cur]) {
        if (p.first == parent)
            continue;
        dfs(p.first, cur);
        dp[cur] = max(dp[cur], dp[p.first] - p.second + gas[cur]);
        if (dp[p.first]-p.second > mx1) {
            mx2 = mx1;
            mx1 = dp[p.first]-p.second;
        } else if (dp[p.first]-p.second > mx2) {
            mx2 = dp[p.first]-p.second;
        }
    }
    ans = max(ans, dp[cur]);
    ans = max(ans, mx2 + mx1 + gas[cur]);
    return;
}
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n;
    gas.resize(n);
    graph.resize(n);
    dp.resize(n);
    for (auto& g : gas) cin >> g;
    for (int i = 0; i < n-1; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    dfs(0, -1);
    cout << ans << endl;      

    return 0;
}
