// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int x = 0; x < t; x++) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        ull dp[2][n+1];
        dp[0][0] = b;
        dp[1][0] = LLONG_MAX;
        for (int i = 1; i < n+1; i++) {
            if (i < n && s[i] == '1') {
                dp[0][i] = LLONG_MAX;
                dp[1][i] = min(dp[1][i-1] + a + 2*b, dp[0][i-1] + 2*a + 2*b);
            } else if (s[i-1] == '1') {
                dp[0][i] = LLONG_MAX;
                dp[1][i] = dp[1][i-1] + a + 2*b;
            } else {
                dp[0][i] = min(dp[1][i-1] + 2*a + b, dp[0][i-1] + a + b);
                dp[1][i] = min(dp[1][i-1] + a + 2*b, dp[0][i-1] + 2*a + 2*b);
            }
        }
        cout << dp[0][n] << endl;
    }


    return 0;
}
