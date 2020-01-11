// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

#define ll long long;
#define ull unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    long long dp[1005];
    dp[0] = 1;
    dp[1] = 1;
    int i = 2;
    while (t--) {
        int n; cin >> n;
        while (i <= n-1) {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007LL;
            i++;
        }
        cout << dp[n-1] << endl;
    }

    return 0;
}

