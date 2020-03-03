// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int n;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur, int no) {
    if (cur == no || visited[cur]) {
        return;
    }
    visited[cur] = 1;
    for (int i = 0; i < (int) graph[cur].size(); i++) {
        if (graph[cur][i] == no) {
            for (int j = 0; j < (int) graph[no].size(); j++) {
                if (graph[no][j] == cur) {
                    graph[no].erase(graph[no].begin()+j);
                    break;
                }
            }
        }
        dfs(graph[cur][i], no);
    }
    graph[cur].clear();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> n;
    graph.resize(n);
    visited.assign(n, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = 1;
    while (true) {
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if ((int) graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        if (leaves.size() < 2) {
            break;
        }
        int node1 = leaves[0], node2 = leaves[1+rand()%(leaves.size()-1)];
        cout << "? " << node1+1 << " " << node2+1 << endl;
        fflush(stdout);
        cin >> res;
        if (res == -1) {
            while (1) ;
        }
        res--;
        if (res != node1) {
            dfs(node1, res);
        } 
        if (res != node2) {
            dfs(node2, res);
        }
        node1 = res;
    }

    cout << "! " << res+1 << endl;
    fflush(stdout);

    return 0;
}
