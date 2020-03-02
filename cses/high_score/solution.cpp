// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 2500;
ll dist[MAX_N]; 
bool visited[MAX_N] = {0};
vector<vector<int>> graph;
int n;

bool dfs(int cur) {
    if (visited[cur]) {
        return 1;
    }
    visited[cur] = 1;
    if (cur == n-1) {
        return 0;
    }
    for (auto& e : graph[cur]) {
        if (!dfs(e)) {
            return 0;
        }
    }
    return 1;
}    

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int m;
    cin >> n >> m;
    vector<array<int,3>> edges;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        edges.push_back({a, b, -x});
        graph[a].push_back(b);
    }
    
    for (int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[0] = 0;

    // Bellman Ford
    for (int i = 0; i < n-1; i++) {
        for (auto& e : edges) {
            if (dist[e[0]] != LLONG_MAX) {
                dist[e[1]] = min(dist[e[1]], dist[e[0]]+e[2]);
            }
        }
    }

    // Detect Negative cycles on path
    bool good = 1;
    for (auto& e : edges) {
        if (dist[e[0]] != LLONG_MAX && dist[e[1]] > dist[e[0]]+e[2]) {
            // Found cycle, check
            good = good && dfs(e[0]);
            if (!good) {
                break;
            }
        }
    }
    
    if (good) {
        cout << -dist[n-1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
