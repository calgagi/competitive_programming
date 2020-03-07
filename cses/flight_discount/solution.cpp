// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 1e5 + 2;
vector<vector<pair<int,ll>>> graph;

ll dijkstra() {
    bool visited[MAX_N][2] = {0};
    priority_queue<tuple<ll,int,bool>, vector<tuple<ll,int,bool>>, greater<tuple<ll,int,bool>>> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        ll dist;
        int cur;
        bool coupon;
        tie(dist, cur, coupon) = q.top();
        q.pop();
        if (visited[cur][coupon]) {
            continue;
        }
        visited[cur][coupon] = 1;
        if (cur == (int)graph.size()-1) {
            return dist;
        }
        for (auto& edge : graph[cur]) {
            q.push({dist+edge.second, edge.first, coupon});
            if (!coupon) {
                q.push({dist+edge.second/2, edge.first, 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    cout << dijkstra() << endl;

    return 0;
}
