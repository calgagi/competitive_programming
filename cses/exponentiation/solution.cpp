// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll res = 1;
    for (int t = 1, i = 0; t <= b; t += i) {
        ll x = a;
        for (i = 1; t+i*2 <= b; i *= 2) {
            x = mult(x, x);
        } 
        res = mult(res, x);
    }

    cout << res << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}
