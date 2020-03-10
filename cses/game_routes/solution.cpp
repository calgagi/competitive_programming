// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MOD = 1e9+7, MAX_N = 1e5+1;
ll ways[MAX_N] = {0};
vector<vector<int>> graph;

ll dfs(int cur, int tar) {
    if (ways[cur] != 0) {
        return ways[cur];
    }
    if (cur == tar) {
        return 1LL;
    }
    ll res = 0;
    for (auto& e : graph[cur]) {
        res = (dfs(e, tar) + res) % MOD;
    }
    ways[cur] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    cout << dfs(0, n-1) << endl;    

    return 0;
}
