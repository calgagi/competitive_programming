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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (!(n & 1)) {
            a[i] *= 2, b[i] *= 2; 
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll mx_mid, mn_mid;
    if ((n & 1)) {
        mx_mid = b[n/2], mn_mid = a[n/2];
    } else {
        mx_mid = (b[n/2]+b[(n-1)/2])/2, mn_mid = (a[n/2]+a[(n-1)/2])/2;
    }

    cout << mx_mid-mn_mid+1 << endl; 
    
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
