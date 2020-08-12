/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

int not_zero(int x) {
    return x != 0;
}

const int MAX_N = 3;
const int MAX_M = 1e6;
bool mode; 
int dp[MAX_M][(1 << MAX_N)];
int n, m;
vector<vector<char>> mat;

int convert(int pos) {
    int val = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (mode) {
            val |= (((int) mat[i][pos] - '0') << i);
        } else {
            val |= (((int) mat[pos][i] - '0') << i);
        }
    }
    return val;
}

void solve() {
    cin >> n >> m;
    mat.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

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
    mode = n < 4;

    // init DP
    for (int i = 0; i < mask_size; i++) {
        dp[0][i] = __builtin_popcount(convert(0) ^ i);
        /* cout << dp[0][i] << " "; */
    }
    /* cout << endl; */

    for (int pos = 1; pos < max(n, m); pos++) {

        // convert column to bitwise representation
        int val = convert(pos);

        for (int mask = 0; mask < mask_size; mask++) {
            dp[pos][mask] = INT_MAX;

            // check if odd number of 1's for each square
            for (int prev_mask = 0; prev_mask < mask_size; prev_mask++) {
                bool good = 1;
                for (int i = 0; i < min(n, m)-1; i++) {
                    int ones = not_zero(prev_mask & (1 << i)) + not_zero(mask & (1 << i)) + 
                               not_zero(prev_mask & (1 << (i+1))) + not_zero(mask & (1 << (i+1)));
                    if (!(ones & 1)) {
                        good = 0;
                        break;
                    }
                }
                if (good) {
                    dp[pos][mask] = min(dp[pos-1][prev_mask] + __builtin_popcount(mask ^ val), dp[pos][mask]);
                }
            }
            /* cout << dp[pos][mask] << " "; */
        }
        /* cout << endl; */
    }

    int ans = INT_MAX;
    for (int i = 0; i < mask_size; i++) {
        ans = min(ans, dp[max(n,m) - 1][i]);
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
