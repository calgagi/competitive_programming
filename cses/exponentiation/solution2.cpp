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

const ll M = 1e9+7;

void solve() {
    ll a, b;
    cin >> a >> b;

    ll ans = 1;
    while (b) {
        if ((b & 1)) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
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
