// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 1e3;
char g[MAX][MAX];
int dp[MAX][MAX];
vector<bool> dead;
queue<array<int,4>> q;
string res = "";
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
ii player;
int n, m;

void build_res(int r, int c) {
    queue<pair<ii, int>> qu;
    qu.push({{r,c}, 0});
    bool vi[MAX][MAX] = {0};
    while (!qu.empty()) {
        ii cur = qu.front().first;
        int d = qu.front().second;
        qu.pop();
        int r = cur.first, c = cur.second;
        if (r < 0 || c < 0 || r >= MAX || c >= MAX || g[r][c] == '#' || vi[r][c]) {
            continue;
        } 
        vi[r][c] = 1;
        dp[r][c] = d;
        for (auto& di : dir) {
            qu.push({{r+di[0], c+di[1]}, d+1}); 
        }
    } 
    
    r = player.first, c = player.second;
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < m; j++) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    while (!(r == n-1 || r == 0 || c == m-1 || c == 0)) {
        if (r > 0 && dp[r][c] == dp[r-1][c]+1) {
            res.push_back('U');
            r--;
        } else if (r < n-1 && dp[r][c] == dp[r+1][c]+1) {
            res.push_back('D');
            r++;
        } else if (c > 0 && dp[r][c] == dp[r][c-1]+1) {
            res.push_back('L');
            c--;
        } else if (c < m-1 && dp[r][c] == dp[r][c+1]+1) {
            res.push_back('R');
            c++;
        }
    }
    return;         
}

bool bfs() {
    vector<int> candidates;
    int prev = -1;
    while (!q.empty()) {
        array<int,4> a = q.front();
        q.pop();
        int r = a[0], c = a[1], type = a[2], d = a[3];
        if (r < 0 || c < 0 || r >= MAX || c >= MAX || g[r][c] == '#' || dp[r][c] != -1) {
            continue;
        }
        dp[r][c] = d;
        if (type == 1 && (r == 0 || c == 0 || r == n-1 || c == m-1)) {
            build_res(r, c);
            return 1;
        }            
        for (auto& di : dir) {
            q.push({r+di[0], c+di[1], type, d+1}); 
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> n >> m;
    
    memset(g, '#', sizeof(g));
    memset(dp, 255, sizeof(dp));

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                player = {i, j};
            } else if (g[i][j] == 'M') {
                q.push({i, j, 0, (int)1e9});
            }
        }
    }
    q.push({player.first, player.second, 1, 0});

    bool ans = bfs();
    if (!ans) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << res.size() << endl;
        cout << res << endl; 
    }
    return 0;
}
