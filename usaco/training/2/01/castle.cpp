/*
ID: calgagi1
LANG: C++
TASK: castle
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

void dfs(vector<vector<int>>& cc, vector<vector<int>>& graph, int i, int j, int m) {
    if (cc[i][j] != -1) {
        return;
    }
    cc[i][j] = m;
    if (graph[i][j] >= 8) {
        graph[i][j] -= 8;
    } else {
        dfs(cc, graph, i+1, j, m);
    }
    if (graph[i][j] >= 4) {
        graph[i][j] -= 4;
    } else {
        dfs(cc, graph, i, j+1, m);
    }
    if (graph[i][j] >= 2) {
        graph[i][j] -= 2; 
    } else {
        dfs(cc, graph, i-1, j, m);
    }
    if (graph[i][j] >= 1) {
        graph[i][j] -= 1;
    } else {
        dfs(cc, graph, i, j-1, m);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("castle.in", "r", stdin), *OUT = freopen("castle.out", "w", stdout); 

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(m, vector<int>(n, -1)), cc(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int counter = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (cc[i][j] == -1) {
                dfs(cc, graph, i, j, ++counter);
            }
        }
    }

    int MAX = 0;
    vector<int> size(counter+1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            size[cc[i][j]]++;
            MAX = max(MAX, size[cc[i][j]]);
        }
    }

    cout << counter << endl;
    cout << MAX << endl;

    // Find wall to be broken
    char dir = 'E';
    MAX = 0;
    ii ans;
    vector<ii> diff = {{-1, 0}, {0, 1}};
    for (int j = 0; j < n; j++) {
        for (int i = m-1; i >= 0; i--) {
            for (auto& p : diff) {
                if (i+p.first >= 0 && i+p.first < m && j+p.second >= 0 && j+p.second < n) {
                    int comp1 = cc[i+p.first][j+p.second], comp2 = cc[i][j];
                    if (comp1 != comp2 && size[comp1]+size[comp2] > MAX) { 
                        MAX = size[comp1]+size[comp2];
                        dir = (p.first == 0 ? 'E' : 'N');
                        ans = {i, j};
                    }
                }
            }
        }
    }

    cout << MAX << endl;
    cout << ans.first+1 << " " << ans.second+1 << " " << dir << endl;

    return 0;
}
