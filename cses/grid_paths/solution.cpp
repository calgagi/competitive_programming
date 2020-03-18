// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n,0));
    const int MOD = 1e9 + 7;
    dp[0][0] = (g[0][0] == '*' ? 0 : 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (g[i][j] != '*') {
                dp[i][j] = ((i ? dp[i-1][j] : 0) + (j ? dp[i][j-1] : 0)) % MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;

    return 0;
}
