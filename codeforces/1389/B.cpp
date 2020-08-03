/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>
 
using namespace std;
#define ld long double
#define ll long long
 
void solve() {
    int n, k, z;
    cin >> n >> k >> z; 
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    ll ans = a[0];
    for (int left = 0; left <= z; left++) {
        if (k - 2*left < 0) {
            break;
        }
        ll best = a[0], best_pair = a[0] + a[1];
        for (int i = 1; i < n && i <= k - 2*left; i++) {
            best += a[i];
            if (i+1 < n) {
                best_pair = max(best_pair, a[i] + a[i+1]);
            }
        }
        ans = max(ans, best + left * best_pair);
    }
        
    cout << ans << endl;
 
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
