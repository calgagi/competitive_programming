// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 1e5;
int visited[MAX_N] = {0};
vector<vector<int>> g;
vector<int> path;

int dfs(int cur) {
    if (visited[cur] == 2) {
        path.push_back(cur); 
        return 1;
    }
    visited[cur] = 2;
    for (auto& neighbor : g[cur]) {
        int r = dfs(neighbor);
        if (r) {
            if (r == 1) {
                path.push_back(cur);
            }
            return (r == 1 && cur != path[0] ? 1 : 2);
        }
    }
    visited[cur] = 1;
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
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a == b) {
            continue;
        }
        g[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i)) {
            cout << path.size() << endl;
            for (int j = path.size()-1; j >= 0; j--) {
                cout << path[j]+1 << " ";
            } 
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
