// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> al(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int,int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (dist[p.first] != INT_MAX) {
            continue;
        }
        dist[p.first] = p.second;
        if (p.first == n-1) {
            break;
        }
        for (auto& e : al[p.first]) {
            if (dist[e] == INT_MAX) {
                q.emplace(e, p.second+1);
            }
        }
    }

    /* for (auto& i : dist) { */
    /*    cout << i << " "; */
    /* } */ 
    /* cout <<endl; */

    if (dist[n-1] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int s = n-1;
        vector<int> path;
        path.push_back(n-1);
        while (s != 0) {
            for (auto e : al[s]) {
                if (dist[e]+1 == dist[s]) {
                    s = e;
                    path.push_back(e);
                    break;
                }
            }
        }
        cout << dist[n-1]+1 << endl;
        for (int i = (int) path.size()-1; i >= 0; i--) {
            cout << path[i]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}
