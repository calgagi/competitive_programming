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

ll test(ll m, vector<ll>& b) {
    ll cur = m;
    int n = b.size();
    for (int i = 0; i < n; i++) {
        if (cur % b[i] == 0) {
            continue;
        } else {
            cur = ((cur / b[i]) + 1LL) * b[i];
        }
    }
    return cur;
}

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll l = 0, r = d, ans = 0;
    
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (test(m, b) <= d) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
