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
    ll a, b, c, d;    
    cin >> a >> b >> c >> d;

    ll n = max(b+c+2, d+2);
    vector<ll> sums(n, 0);

    for (ll i = c+1; i < n; i++) {
        ll y = c;
        ll x = i-y;
        if (a > x) {
            ll diff = a-x;
            x = a;
            y -= diff;
        }
        ll x_range = b-x+1, y_range = y-b+1;
        sums[i] = min(x_range, y_range);
        sums[i] = max(0LL, sums[i]);
    }

    for (int i = n-2; i >= 0; i--) {
        sums[i] += sums[i+1]; 
    }

    ll ans = 0;
    for (ll z = c; z <= d; z++) {
        ans += sums[z+1];
    }

    cout << ans << endl;

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
