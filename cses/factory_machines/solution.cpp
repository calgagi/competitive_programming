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

ll test(vector<ll>& machine, ll time, ll t) {
    ll ans = 0;
    for (int i = 0; i < (int) machine.size(); i++) {
        ans += time / machine[i];
        if (ans >= t) {
            return 1;
        }
        if (time / machine[i] == 0) {
            return 0;
        }
    }
    return 0;
}

void solve() {
    int n, t;
    cin >> n >> t;
    vector<ll> machine(n);
    for (int i = 0; i < n; i++) {
        cin >> machine[i];
    }

    sort(machine.begin(), machine.end());

    ll l = 0, r = LLONG_MAX, ans = LLONG_MAX;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (test(machine, m, t)) {
            ans = m;
            r = m-1;
        } 
        else {
            l = m+1;
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
