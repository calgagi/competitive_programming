/*
ID: calgagi1
LANG: C++
TASK: nocows
*/
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

const int M = 9901;
vector<vector<vector<int>>> dp;

void dfs(int h, int n) {
    if (dp[h][n][1] != -1) {
        return; 
    }
    dp[h][n][0] = dp[h][n][1] = 0;
    if (n == 1) {
        dp[h][n][0] = h != 0;
        dp[h][n][1] = h == 0;
        return;
    } else if (h == 0) {
        return;
    }
    for (int l = 1; l < n; l += 2) {
        dfs(h-1, l), dfs(h-1, n-l-1);
        dp[h][n][1] += dp[h-1][l][0]*dp[h-1][n-l-1][1];
        dp[h][n][1] %= M;
        dp[h][n][1] += dp[h-1][l][1]*dp[h-1][n-l-1][1];
        dp[h][n][1] %= M;
        dp[h][n][1] += dp[h-1][l][1]*dp[h-1][n-l-1][0];
        dp[h][n][1] %= M;
        dp[h][n][0] += dp[h-1][l][0]*dp[h-1][n-l-1][0];
        dp[h][n][0] %= M;
    }
    return; 
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("nocows.in", "r", stdin), *OUT = freopen("nocows.out", "w", stdout); 
    
    int n, k;
    cin >> n >> k;

    dp.assign(k, vector<vector<int>>(n+1, vector<int>(2, -1)));
    dfs(k-1, n);

    cout << dp[k-1][n][1] << endl;

    return 0;
}
