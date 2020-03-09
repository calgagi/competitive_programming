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
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }
    
    // Kahn's
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto& e : graph[i]) {
            indegree[e]++;
        }
    }
    vector<int> fringe;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            fringe.push_back(i);
        }
    }
    vector<int> top_sort;
    while (!fringe.empty()) {
        vector<int> new_fringe;
        for (int i = 0; i < (int) fringe.size(); i++) {
            for (auto& e : graph[fringe[i]]) {
                indegree[e]--;
                if (indegree[e] == 0) {
                    new_fringe.push_back(e);
                } 
            }
        }
        top_sort.insert(top_sort.begin()+top_sort.size(), fringe.begin(), fringe.end());
        fringe = new_fringe;
    }

    if ((int) top_sort.size() == n) {
        for (auto& i : top_sort) {
            cout << i+1 << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
