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

const char black = '#', white = '.';
vector<vector<char>> mat;
vector<vector<bool>> visit;
const vector<ii> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
int n, m;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j] || mat[i][j] == white) {
        return;
    }
    visit[i][j] = 1;
    for (const ii& d : dir) {
        dfs(i+d.f, j+d.s);
    }
    return;
}

void solve() {
    cin >> n >> m;
    mat.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int p_ans = 0;
    visit.assign(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == black && !visit[i][j]) {
                dfs(i, j); 
                p_ans++;
            }
        }
    }

    if (p_ans == 0) {
        cout << 0 << endl;
        return;
    }

    bool all_white_row = 0, all_white_col = 0;

    // check if invalid rows 
    for (int i = 0; i < n; i++) {
        bool seen_black = 0, seen_white_after_black = 0;
        for (int j = 0; j < m; j++) {
            if (seen_black && seen_white_after_black && mat[i][j] == black) {
                cout << -1 << endl;
                return;
            } 
            if (mat[i][j] == black) {
                seen_black = 1;
            }
            if (seen_black && mat[i][j] == white) {
                seen_white_after_black = 1;
            }
        }
        if (!seen_black) {
            all_white_row = 1;
        }
    }
    
    // check if invalid cols
    for (int j = 0; j < m; j++) {
        bool seen_black = 0, seen_white_after_black = 0;
        for (int i = 0; i < n; i++) {
            if (seen_black && seen_white_after_black && mat[i][j] == black) {
                cout << -1 << endl;
                return;
            } 
            if (mat[i][j] == black) {
                seen_black = 1;
            }
            if (seen_black && mat[i][j] == white) {
                seen_white_after_black = 1;
            }
        }
        if (!seen_black) {
            all_white_col = 1;
        }
    }

    int all_white = all_white_col + all_white_row;
    if (all_white == 1) {
        cout << -1 << endl;
        return;
    }

    cout << p_ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
