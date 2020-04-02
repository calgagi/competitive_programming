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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    string s, t;
    cin >> s >> t;

    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX)); 
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } 
            dp[i][j] = min({dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}
