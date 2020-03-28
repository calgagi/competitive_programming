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

int n, m;
vector<bool> used;
vector<vector<int>> g, gr;
vector<vector<int>> components;
int cc = 0;
vector<int> order;
vector<int> which_scc;
ll ans = 0;

void dfs(int u) {
    used[u] = 1;
    for (auto& v : g[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
    order.push_back(u);
    return;
}

void dfs2(int u) {
    used[u] = 1;
    components[cc].push_back(u);
    which_scc[u] = cc;
    for (auto& v : gr[u]) {
        if (!used[v]) {
            dfs2(v);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    which_scc.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    // Algorithm:
    // 1. Find SCCs
    // 2. Topological sort, keep track of how many vertices are before each SCC
    // 3. Answer = For each SCC, sum of n - SIZE_cur_scc - SIZE_before_scc - DEGREE_out_cur_scc

    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    
    used.assign(n,0);
    for (int i = n-1; i >= 0; i--) {
        if (!used[order[i]]) {
            components.push_back(vector<int>());
            dfs2(order[i]);
            cc++;
        } 
    }
    
    ll sum = n;
    used.assign(cc, 0);
    for (int i = 0; i < cc; i++) {
        if (!used[i]) {
            dfs3(i, sum);
        }
    }

    return 0;
}
