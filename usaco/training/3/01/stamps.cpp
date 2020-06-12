/*
ID: calgagi1
LANG: C++
TASK: stamps
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
#define dd long double

const int DEF = 1e9;

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> stamps(n);
    for (int i = 0; i < n; i++) {
        cin >> stamps[i];
    }

    sort(stamps.begin(), stamps.end());

    vector<int> dp(k*stamps.back()+1, DEF);
    dp[0] = 0;

    int streak = 0, ans = 0;
    for (int i = 1; i < (int) dp.size(); i++) {
        for (int& stamp : stamps) {
            if (i-stamp >= 0) {
                dp[i] = min(dp[i-stamp]+1, dp[i]);
            }
        }
        if (dp[i] != DEF && dp[i] <= k) {
            streak++;
        } else {
            streak = 0;
        }
        ans = max(streak, ans);
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("stamps.in", "r", stdin), *OUT = freopen("stamps.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
