// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int mxN = 2500+2;
ll dist[mxN] = {LLONG_MAX};
int pred[mxN];
vector<vector<ii>> g;
vector<array<int,3>> edge_list;
bool visited[mxN] = {0};

void find_cycle(int u) {
    vector<int> path;
    bool visited[mxN] = {0};
    path.push_back(u);
    while (!visited[u]) {
        visited[u] = 1;
        u = pred[u];
        path.push_back(u);
    }  
    vector<int> real_path = {path.back()};
    for (int i = path.size()-2; i >= 0 && path[i] != u; i--) {
        real_path.push_back(path[i]);
    }
    real_path.push_back(real_path.front());
    for (auto& v : real_path) {
        cout << v+1 << " ";
    }
    cout << endl;
    return;
}

void build(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = 1;
    for (auto& e : g[u]) {
        edge_list.push_back({u, e.first, e.second});
        build(e.first);
    }
    return;
}    

bool bellman_fords(int s, int n) {
    edge_list.clear();
    build(s);
    for (int i = 0; i < mxN; i++) {
        dist[i] = LLONG_MAX;
        pred[i] = -1;
    }
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        for (auto& edge : edge_list) {
            int u =  edge[0], v = edge[1], d = edge[2];
            if (dist[u] != LLONG_MAX && dist[v] > dist[u]+d) {
                dist[v] = dist[u]+d;
                pred[v] = u;
            }
        }
    }
    
    // detect cycle
    for (auto& edge : edge_list) {
        int u =  edge[0], v = edge[1], d = edge[2];
        if (dist[u] != LLONG_MAX && dist[v] > dist[u] + d) {
            cout << "YES" << endl;
            pred[v] = u;
            find_cycle(v);
            return 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == LLONG_MAX) {
            if (bellman_fords(i, n)) {
                return 0;
            }
        }
    } 

    cout << "NO" << endl;

    return 0;
}
