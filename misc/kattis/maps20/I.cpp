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
    // 3. Answer = For each SCC, sum (below_nodes * size_of_SCC) - out_degree_of_SCC 


    // 1: kosaraju's
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

    vector<set<int>> meta(cc);
    vector<int> meta_edges(cc,0);
    for (int i = 0; i < cc; i++) {
        for (auto& node : components[i]) {
            for (auto& edge : g[node]) {
                if (which_scc[edge] != i) {
                    meta[i].insert(which_scc[edge]);
                    meta_edges[i]++;
                }
            }
        }
    }

    /* for (auto& s : meta) { */
    /*     cout << s.size() << endl; */
    /*     for (auto& e : s) { */
    /*         cout << e << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    ll ans = 0;
    ll cur = n;

    // 2: kahn's
    vector<int> fringe, counts(cc,0); 
    for (int i = 0; i < cc; i++) {
        for (auto& edge : meta[i]) {
            counts[edge]++;
        }
    }
    for (int i = 0; i < cc; i++) {
        if (counts[i] == 0) {
            fringe.push_back(i);
        }
    }

    while (!fringe.empty()) {
        vector<int> new_fringe;
        for (int i = 0; i < (int) fringe.size(); i++) {
            for (auto& edge : meta[fringe[i]]) {    
                counts[edge]--;
                if (counts[edge] == 0) {
                    new_fringe.push_back(edge);
                }
            }
            cur -= components[fringe[i]].size();
            ans += (cur * components[fringe[i]].size()) - meta_edges[fringe[i]];
        }
        fringe = new_fringe;
    }

    cout << ans << endl;

    return 0;
}
