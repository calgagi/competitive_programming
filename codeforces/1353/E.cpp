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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            sum++;
        }
    }

    int ans = sum;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = i-k < 0 ? sum : dp[i-k][0];
        dp[i][1] = i-k < 0 ? sum : dp[i-k][1];
        if (s[i] == '1') {
            dp[i][1]--;
        } else {
            dp[i][1]++;
        }
        dp[i][1] = min(sum, dp[i][1]);
        dp[i][0] = min(dp[i][0], dp[i][1]);
        ans = min({dp[i][0], dp[i][1], ans});
    }

    /* for (int i = 0; i < n; i++) { */
    /*     cout << dp[i] << " "; */
    /* } */
    /* cout << endl; */


    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
