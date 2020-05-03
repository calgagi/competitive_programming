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

const ll MX = 1e6, MOD = 1e9+7;
ll fact[MX+1];


ll inverse(ll a) {
    ll x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = MOD;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x-q*x1);
        tie(y, y1) = make_tuple(y1, y-q*y1);
        tie(a1, b1) = make_tuple(b1, a1-q*b1);
    }
    return (x % MOD + MOD) % MOD;
}

void solve() {
    int a, b;
    cin >> a >> b;

    ll ans = ((fact[a] * inverse(fact[b])) % MOD) * inverse(fact[a-b]) % MOD;
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;

    fact[0] = 1;
    for (ll i = 1; i < MX+1; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
        

    while (n--) {
        solve();
    }

    return 0;
}
