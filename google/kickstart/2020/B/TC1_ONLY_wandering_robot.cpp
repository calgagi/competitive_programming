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

void solve() {
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    
    vector<vector<dd>> dp(w + 1, vector<dd>(h + 1, 0.0));
    dp[1][1] = 1.0;
    
    /* cout << endl; */
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            if ((i == 1 && j == 1) || (i <= r && i >= l && j >= u && j <= d)) {
                /* cout << dp[i][j] << " "; */
                continue;
            }
            if (i == w && j == h) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            } else if (i == w) {
                dp[i][j] = dp[i][j - 1] + .5 * dp[i - 1][j];
            } else if (j == h) {
                dp[i][j] = .5 * dp[i][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = .5 * dp[i][j - 1] + .5 * dp[i - 1][j];
            }
            /* cout << dp[i][j] << " "; */
        }
        /* cout << endl; */
    }

    cout << dp[w][h] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    cout << fixed << showpoint << setprecision(6);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
