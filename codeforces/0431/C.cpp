// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll m = 1000000007;
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<ll> > dp(n+1, vector<ll>(2, 0));
    // Index 0 = No edge with >= d weight, 1 = Yes edge with >= d weight
    // There is 1 path of length 0 that doesn't pass minimum K singular weighted edge
    dp[0][0] = 1;

    // For the total path length
    for (int i = 1; i < n+1; i++) {
        // Accumulate past path weights
        // Since there are k edges from this node,
        // we must go through each one of them.
        for (int j = 1; j <= k; j++) {
            // If this edge weight is greater than 
            // the total amount, just break.
            if (j > i) break;

            // If this edge weight is less than d
            if (j < d) {
                dp[i][0] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            // If this edge weight is greater than or equal to d
            } else {
                dp[i][1] += dp[i-j][1];
                dp[i][1] += dp[i-j][0];
            }
            dp[i][1] %= m;
            dp[i][0] %= m;
        }
    }
        
        
    cout << dp[n][1] << endl;

    return 0;
}
