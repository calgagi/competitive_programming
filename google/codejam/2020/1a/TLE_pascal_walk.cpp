/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const int M = 34;
ll pascals[M][M];
bool visited[M][M];
vector<ii> path;
ll dir[6][2] = {{0,-1},{-1,-1},{0,-1},{0,1},{1,1},{0,1}};

void generate_pascals() {
    memset(pascals, 0, sizeof(pascals));
    for (int i = 0; i < 32; i++) {
        pascals[i][0] = 1;
        for (int j = 1; j < i; j++) {
            pascals[i][j] = pascals[i-1][j-1]+pascals[i-1][j];
        }
        pascals[i][i] = 1;
    }
}

bool dfs(int i, int j, ll s, int p) {
    //cout << i << " " << j << endl;
    if (++p > 500 || i < 0 || j < 0 || j >= M || i >= M || visited[i][j] || pascals[i][j] == 0) {
        return 0;
    }
    visited[i][j] = 1;
    s -= pascals[i][j];
    if (s < 0) {
        return 0;
    } else if (s == 0) {
        path.push_back({i,j});
        return 1;
    }
    for (auto& d : dir) {
        if (dfs(i+d[0], j+d[1], s, p)) {
            path.push_back({i,j});
            return 1;
        } 
    }
    visited[i][j] = 0;
    return 0;
}

void solve() {
    ll n;
    cin >> n;
    memset(visited, 0, sizeof(visited));
    path.clear();
    dfs(0, 0, n, 0);
    reverse(path.begin(), path.end());
    cout << endl;
    for (auto& p : path) {
        cout << p.f+1 << " " << p.s+1 << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    generate_pascals();
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}

