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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll len = 0, ans = 0;

    ll b = a[0];
    bool neg = a[0] < 0;
    for (int i = 1; i < n; i++) {
        if (neg) {
            if (a[i] > 0) {
                ans += b;
                neg = !neg;
                b = a[i];
            } else {
                b = max(b, a[i]);
            }
        } else {
            if (a[i] < 0) {
                ans += b;
                neg = !neg;
                b = a[i];
            } else {
                b = max(b, a[i]);
            }
        }
    }
    ans += b;

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
    while (t--) {
        solve();
    }

    return 0;
}
