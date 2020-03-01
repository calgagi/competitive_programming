// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 1001;
char g[MAX][MAX];
int dist[MAX][MAX];
int d[4][3] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
pair<int,int> a, b;

string res = "";

void build_res() {
    int r = b.first, c = b.second;
    while (r != a.first || c != a.second) {
        if (r-1 >= 0 && dist[r-1][c]+1 == dist[r][c]) {
            r--;
            res += 'D';
        } else if (r+1 < MAX && dist[r+1][c]+1 == dist[r][c]) {
            r++;
            res += 'U';
        } else if (c-1 >= 0 && dist[r][c-1]+1 == dist[r][c]) {
            c--;
            res += 'R';
        } else if (c+1 < MAX && dist[r][c+1]+1 == dist[r][c]) {
            c++;
            res += 'L';
        }
    }
    return;
}

bool bfs() {
    queue<tuple<int,int,int>> q;
    q.emplace(make_tuple(a.first, a.second, 0)); 
    memset(dist, 255, sizeof(dist));

    while (!q.empty()) {
        int r, c, k;
        tie(r, c, k) = q.front();
        q.pop();
        if (r < 0 || c < 0 || c >= MAX || r >= MAX || g[r][c] == '#') {
            continue;
        }
        dist[r][c] = k;
        g[r][c] = '#';
        if (r == b.first && c == b.second) {
            build_res();
            return 1;
        }
        for (auto dir : d) {
            if (r+dir[0] < 0 || c+dir[1] < 0 || c+dir[1] >= MAX || r+dir[0] >= MAX || g[r+dir[0]][c+dir[1]] == '#') {
                continue;
            }
            q.push(make_tuple(r+dir[0], c+dir[1], k+1));
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    memset(g, '#', sizeof(g));
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                a = {i, j};
            } else if (g[i][j] == 'B') {
                b = {i, j};
            }
        }
    }

    bool z = bfs();
    if (z) {
        cout << "YES" << endl;
        cout << res.size() << endl;
        reverse(res.begin(),res.end());
        cout << res << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
