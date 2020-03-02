// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 1e5;
ll dist[MAX];
vector<vector<pair<int,ll>>> g;

void dijkstras() {
    memset(dist, 255, sizeof(dist));
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        ll d = q.top().first;
        int i = q.top().second;
        q.pop();
        if (dist[i] != -1) {
            continue;
        }
        dist[i] = d;
        for (auto& e : g[i]) {
            q.emplace(e.second+d, e.first);
        }
    }
    return;
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
        g[a].emplace_back(b, c);
    }

    dijkstras();

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
