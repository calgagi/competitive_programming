/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    string a, b;
    cin >> b >> a;
    int n = b.length(), m = a.length();

    if (m > n) {
        cout << 0 << endl;
        return;
    }

    ll a_hash = 0;
    const ll MOD = 1e14 + 7, multiplier = 31;
    ll pos = 1;
    for (int i = m-1; i >= 0; i--) {
        a_hash = (a_hash + (pos * (a[i] - 'a'))) % MOD;
        pos = (multiplier * pos) % MOD;
    }

    int ans = 0;

    ll prev_pos = 1;
    pos = 1;
    ll b_hash = 0;
    for (int i = m-1; i >= 0; i--) {
        prev_pos = pos;
        b_hash = (b_hash + (pos * (b[i] - 'a'))) % MOD;
        pos = (multiplier * pos) % MOD;
    }

    pos = prev_pos;
     
    if (b_hash == a_hash) {
        ans++;
    }

    for (int i = m; i < n; i++) {
        b_hash -= ((b[i-m] - 'a') * pos);
        b_hash %= MOD;
        if (b_hash < 0) {
            b_hash += MOD;
        }

        b_hash = (b_hash * multiplier) % MOD;
        b_hash += (b[i] - 'a');
        b_hash %= MOD;

        if (b_hash == a_hash) {
            ans++;
        }
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
