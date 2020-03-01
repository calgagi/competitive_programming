// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 1000;
char graph[MAX+1][MAX+1];
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j) {
    if (i < 0 || i >= MAX || j < 0 || j >= MAX || graph[i][j] == '#') {
        return;
    }
    graph[i][j] = '#';
    for (auto& p : dir) {
        dfs(i+p[0], j+p[1]);
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
    memset(graph, '#', sizeof(graph));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int  j = 0; j < m; j++) {
            if (graph[i][j] != '#') {
                res++;
                dfs(i, j);
            }
        }
    } 

    cout << res << endl;

    return 0;
}
