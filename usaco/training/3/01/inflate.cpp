/*
ID: calgagi1
LANG: C++
TASK: inflate
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

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> points(n), minutes(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i] >> minutes[i];
    }

    vector<ll> dp(m+1, -1);
    dp[0] = 0;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j+minutes[i] <= m; j++) {
            if (dp[j] != -1) {
                dp[j+minutes[i]] = max(dp[j+minutes[i]], dp[j]+points[i]);
                ans = max(dp[j+minutes[i]], ans);
            }
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("inflate.in", "r", stdin), *OUT = freopen("inflate.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
