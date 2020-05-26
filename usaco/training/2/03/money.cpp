/*
ID: calgagi1
LANG: C++
TASK: money
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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("money.in", "r", stdin), *OUT = freopen("money.out", "w", stdout); 

    int v, n;
    cin >> v >> n;
    vector<ll> coins(v);
    for (ll& x : coins) {
        cin >> x;
    }

    vector<ll> dp(n+1);
    dp[0] = 1;
    for (ll& coin : coins) {
        for (ll i = coin; i <= n; i++) {
            dp[i] += dp[i-coin];
        }
    }

    cout << dp[n] << endl;

    return 0;
}
