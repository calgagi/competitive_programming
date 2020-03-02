// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

bool dfs(vector<vector<int>>& g, vector<int>& c, int cur, int color) {
    if (c[cur] != 0) {
        return c[cur] == color;
    }
    c[cur] = color;
    bool res = true;
    for (auto& e : g[cur]) {
        res = res && dfs(g, c, e, (color==1?2:1));
        if (!res) {
            break;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(n, 0);
    bool res = true;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            res = res && dfs(g, c, i, 1);
            if (!res) {
                break;
            }
        } 
    }

    if (res == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
