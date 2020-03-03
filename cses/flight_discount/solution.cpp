// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 1e5+1;
ll dp[MAX_N][2];
bool visited[MAX_N] = {0};
int n, m;
vector<vector<pair<int,ll>>> graph;

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }
    visited[cur] = 1;
    for (auto& e : graph[cur]) {
        dfs(e.first);
        if (dp[e.first][0] == LLONG_MAX && dp[e.first][1] == LLONG_MAX) {
            continue;
        }
        dp[cur][0] = min(dp[cur][0], dp[e.first][0] + e.second);
        dp[cur][1] = min({dp[cur][1], dp[e.first][0] + e.second/2, dp[e.first][1] + e.second});
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    for (int i = 0; i < MAX_N; i++) {
        dp[i][0] = dp[i][1] = LLONG_MAX;
    }

    cin >> n >> m;
    dp[n-1][0] = dp[n-1][1] = 0;
    visited[n-1] = 1;
    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b,c});
    }

    dfs(0); 

    cout << min(dp[0][0], dp[0][1]) << endl;

    return 0;
}
