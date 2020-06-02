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

vector<vector<int>> graph;
vector<int> num_mismatch_tree;
vector<int> cost, goal, current;
vector<int> num1_tree, num0_tree;
vector<bool> visit, good;

vector<ll> dp;

void predfs(int u) {
    visit[u] = 1;
    
    for (int v : graph[u]) {
        if (!visit[v]) {
            num1_tree[u] += num1_tree[v];
            num0_tree[u] += num0_tree[v];
            num_mismatch_tree[u] += num_mismatch_tree[v];
        }
    }

    if (goal[u] != current[u]) {
        if (current[u] == 1) {
            num1_tree[u]++;
        } else {
            num0_tree[u]++;
        }
        num_mismatch_tree[u]++;
    }

    return;
}

void dfs(int u) {
    visit[u] = 1;

    good[u] = 1;
    ll ans = 0;
    for (int v : graph[u]) {
        if (!good[v]) {
            good[u] = 0;
        }
        ans += dp[v];
    }
    
    if (good[u] && goal[u] == current[u]) {
        dp[u] = ans;
    }

    if (num0_tree[u] == num1_tree[u]) {
        dp[u] = min((ll) num_mismatch[u] * cost[u], dp[u]);
        good[u] = 1;
    }

    return;
}


void solve() {
    int n;
    cin >> n;
    graph.resize(n);
    cost.resize(n), goal.resize(n), current.resize(n);
    num1_tree.resize(n), num0_tree.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i] >> current[i] >> goal[i];
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visit.assign(n, 0);

    predfs(0);

    visit.assign(n, 0);
    good.assign(n, 0);
    dp.assign(n, LLONG_MAX);

    dfs(0);

    cout << dp[0] << endl;

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
