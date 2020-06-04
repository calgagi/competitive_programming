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
    vector<dd> a(n);
    for (dd& x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    dd ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= a[i];
        if (ans > 1e18) {
            break;
        }
    }

    cout << fixed << setprecision(0);
    if (ans > 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


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
