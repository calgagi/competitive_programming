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
    ll a, b, q;
    cin >> a >> b >> q;

    if (a > b) {
        swap(a, b);
    }

    ll m = a*b;
    
    vector<int> pre(m, 0);
    pre[0] = 0;
    for (ll i = 1; i < m; i++) {
        if ((i % a) % b != (i % b) % a) {
            pre[i] = 1;
        }
        pre[i] += pre[i-1];
    }

    ll tot = pre[m-1];
    
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;

        ll totr = tot*(r/m) + pre[r % m], totl = tot*(l/m) + pre[l % m];

        ll ans = totr - totl; 
        ans += ((l % a) % b != (l % b) % a);

        cout << ans << " ";
    } 

    cout << endl;

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
