// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, p, k; cin >> n >> p >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());
    vector<int> dp(n+1, 0);
    int ans = 0;
    for (int i = 1; i < n+1; i++) {
        dp[i] = min(a[i-1] + dp[i-1], (i-k>=0?dp[i-k]+a[i-1]:INT_MAX));
        if (dp[i] <= p)
            ans = max(ans, i);
    }
    cout << ans << endl;
    return;
}
    



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());


    int t; cin >> t;
    while (t--) solve();

    return 0;
}
