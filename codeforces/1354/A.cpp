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

    ll ans = 0;
    ans += b;

    if (ans >= a) {
        cout << ans << endl;
        return;
    }

    if (c <= d) {
        cout << -1 << endl;
        return;
    }

    dd diff = d - c;

    dd needed = (b - a);

    ans += ceil(needed/diff) * c;

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
