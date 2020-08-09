/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

vector<pair<int,int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
vector<pair<int,int>> dir2 = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

void solve() {
    int n, m;
    cin >> n >> m;
    char cloth[n+2][m+2];
    memset(cloth, '\0', sizeof(cloth));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cloth[i][j];
        }
    }

    ll dp[n+2][m+2][4];
    memset(dp, 0, sizeof(dp));

    for (int d = 0; d < 4; d++) {
        for (int row = (dir2[d].first == 1 ? 1 : n); row <= n && row; row += dir2[d].first) {
            for (int col = (dir2[d].second == 1 ? 1 : m); col <= m && col; col += dir2[d].second) {
                if (cloth[row][col] != cloth[row-dir2[d].first][col] ||
                    cloth[row][col] != cloth[row][col-dir2[d].second]) {
                    dp[row][col][d] = 1;
                } else {
                    dp[row][col][d] = min(
                        dp[row-dir2[d].first][col][d],
                        dp[row][col-dir2[d].second][d]
                    ) + 1;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll cur = 1e9;
            for (int d = 0; d < 4; d++) {
                cur = min(cur, dp[i][j][d]);
            }
            ans += cur;
        }
    }

    cout << ans << endl;

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
