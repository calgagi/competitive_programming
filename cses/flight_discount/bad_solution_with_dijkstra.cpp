// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 1e5 + 1;
ll dist[MAX_N];
ii pred[MAX_N];
vector<vector<ii>> adj;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    memset(dist, 255, sizeof(dist));
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b,c});
    }

    // Dijkstra
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    q.push({0, 0, -1, 0});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (dist[p[1]] != -1) {
            continue;
        }
        dist[p[1]] = p[0];
        pred[p[1]] = {p[2], p[3]}; 
        for (auto& e : adj[p[1]]) {
            q.push({(ll)e.second+p[0], e.first, p[1], (ll)e.second});
        }
    }

    /* for (int i = 0; i < n; i++) { */
    /*     cout << dist[i] << " " << pred[i].first << endl; */
    /* } */

    // Find longest part
    ll y = INT_MIN;
    int x = n-1;
    while (x != 0) {
        y = max(y, (ll)pred[x].second);
        x = pred[x].first;
    }

    cout << dist[n-1]-(y+1)/2 << endl;
         
    return 0;
}
