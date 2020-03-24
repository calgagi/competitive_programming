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

const int MOD = 1e9+7, MAX_N = 1e5, MAX_M = 100;
int n, m;
ll dp[MAX_N+1][MAX_M+2];
int a[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) {
            dp[i][a[i]] = 1;
        }
    }

    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1; 
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i-1][j]+(j>0?dp[i-1][j-1]:0)+(j<m?dp[i-1][j+1]:0)) % MOD;
            }
        } else {
            int j = a[i];
            dp[i][j] = (dp[i-1][j]+(j>0?dp[i-1][j-1]:0)+(j<m?dp[i-1][j+1]:0)) % MOD;
        }
    }

    int res = 0;
    for (int i = 0; i <= m; i++) {
        res = (res + dp[n-1][i]) % MOD;
    }

    cout << res << endl;

    return 0;
}
