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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    } 

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(i & 1)) {
            ans += a[i];
        }
    }

    ll diff = 0;
    ll master_diff = 0;

    // even offset
    for (int i = 0; i < n-1; i += 2) {
        diff += a[i+1] - a[i];
        if (diff < 0) {
            diff = 0;
        }
        master_diff = max(diff, master_diff);
    }

    // odd offset
    diff = 0;
    for (int i = 1; i < n-1; i += 2) {
        diff += a[i] - a[i+1];
        if (diff < 0) {
            diff = 0;
        }
        master_diff = max(diff, master_diff);
    }

    cout << ans + master_diff << endl;

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
