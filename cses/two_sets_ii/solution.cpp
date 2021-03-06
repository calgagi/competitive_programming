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

const ll M = 1e9 + 7;

void solve() {
    ll N;
    cin >> N;

    ll sum = N * (N+1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    sum /= 2LL;

    vector<ll> dp(sum+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        vector<ll> new_dp = dp;
        for (int j = 0; j <= sum - i; j++) {
            new_dp[j+i] = (new_dp[j+i] + dp[j]) % M;
        }
        dp = new_dp;
    }

    cout << dp[sum] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
