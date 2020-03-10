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
vector<vector<int>> adj;
int n;
int to[MAX_N] = {-1};
int cache[MAX_N] = {0};

vector<int> generate_path() {
    vector<int> path;
    int cur = 0;
    while (cur != n-1) {
        path.push_back(cur);
        cur = to[cur];
    }
    path.push_back(n-1);
    return path;
}
        

int dfs(int cur) {
    if (cur == n-1) {
        return 1;
    } 
    if (cache[cur] != 0) {
        return cache[cur];
    }
    int res = -1;
    for (auto& e : adj[cur]) {
        int v = dfs(e);
        if (v != -1 && res < v+1) {
            to[cur] = e;
            res = v+1;
        }
    }
    cache[cur] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    // DAG
    if (dfs(0) == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        /* for (int i = 0; i < n; i++) { */
        /*     cout << i << ": " << to[i] << "," << cache[i] << endl; */
        /* } */
        vector<int> path = generate_path();
        cout << path.size() << endl;
        for (auto& p : path) {
            cout << p+1 << " ";
        } 
        cout << endl;
    }

    return 0;
}
