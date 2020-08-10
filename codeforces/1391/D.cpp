/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    if (m < n) {
        

    // if big matrix, then cannot make (think 4 2x2's with odd 1's = 1 4x4 with even 1's)
    if (n >= 4 && m >= 4) {
        cout << -1 << endl;
        return;
    }

    // must be <= 3
    if (n == 1 || m == 1) {
        cout << 0 << endl;
        return;
    }

    // must != 1, which means we need to do work
    int mask_size = (1 << min(n, m));
    int dp[max(n, m)][max_size];
    for (int i = 0; i < (1 << 

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
