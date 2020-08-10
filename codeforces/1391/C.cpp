/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

const ll MOD = 1e9 + 7, MAX_N = 1e6+1;
ll fact[MAX_N];

void solve() {
    int n;
    cin >> n;

    ll ans = fact[n];
    if (n == 2) {
        cout << ans << endl;
        return;
    }
    ll sub = 1;
    for (int i = 0; i < n-1; i++) {
        sub *= 2LL;
        sub %= MOD;
    }

    ans -= sub;
    if (ans < 0) {
        ans += MOD;
    }

    cout << ans << endl;

    return;
}

void preprocess() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 

    preprocess();
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
