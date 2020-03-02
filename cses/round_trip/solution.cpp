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
bool visited[MAX_N];
vector<int> path;
vector<vector<int>> g;

int dfs(int c, int par) {
    if (visited[c]) {
        path.push_back(c);
        return 1;
    }
    visited[c] = 1;
    for (auto& e : g[c]) {
        if (e != par) {
            int cyclic = dfs(e, c);
            if (cyclic == 1) {
                path.push_back(c);
                return (path[0] == c ? 2 : 1);
            } else if (cyclic == 2) {
                return 2;
            }
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
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));

    bool ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans = ans || dfs(i, -1);
        }
        if (ans) {
            break;
        }
    }
    if (!ans) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << path.size() << endl;
        for (int i = path.size()-1; i >= 0; i--) {
            cout << path[i]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}
