// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 1e5+2;
vector<vector<ii>> graph;
vector<vector<ll>> dists;
int k;

void dijkstras() {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0,0});
    while (!q.empty()) {
        ll d = q.top().first;
        int cur = q.top().second;
        q.pop();
        if ((int) dists[cur].size() < k) {
            dists[cur].push_back(d);
        } else {
            continue;
        }
        for (auto& edge : graph[cur]) {
            q.push({(ll)edge.first + d, edge.second});
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
    cin >> n >> m >> k;
    dists.resize(n);
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({c,b});
    }

    /* for (int i = 0; i < n; i++) { */
    /*     sort(graph[i].begin(), graph[i].end()); */
    /* } */

    dijkstras();

    for (auto& p : dists[n-1]) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
