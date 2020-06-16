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

const ll MOD = 1e9+7, MAXN = 1e6;
ll factorial[MAXN+1];

void preprocess() {
    factorial[1] = factorial[0] = 1;
    for (ll i = 2; i <= MAXN; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    return;
}

ll inverse(ll a, int p) {
    ll ans = 1;
    ll b = 1;
    while (p) {
        if ((p & 1)) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        p >>= 1;
    }
    return ans;
}

ll choose(ll n, ll k) { 
    return ((factorial[n] * inverse(factorial[k], MOD-2) % MOD) * inverse(factorial[n-k], MOD-2)) % MOD;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }

    ll ans = 1;
    for (int i = 0; n && i < 26; i++) {
        ans = (ans * choose(n, cnt[i])) % MOD;
        n -= cnt[i];
    } 

    cout << ans << endl;

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
