/*
ID: calgagi1
LANG: C++
TASK: subset
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
    FILE *IN = freopen("subset.in", "r", stdin), *OUT = freopen("subset.out", "w", stdout); 


    ll n;
    cin >> n;
    
    ll v = (n*(n+1))/2;
    if ((v & 1)) {
        cout << 0 << endl;
        return 0;
    }

    ll target = v/2;
    
    vector<ll> dp(target+1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        vector<ll> new_dp = dp;
        for (int j = 0; j <= target; j++) {
            if (j-i >= 0) {
                new_dp[j] += dp[j-i];
            }
        }
        dp = new_dp;
    }

    cout << dp[target]/2 << endl;

    return 0;
}
