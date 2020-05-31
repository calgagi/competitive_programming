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
    dd c, h, t;
    cin >> h >> c >> t;

    if (t >= h) {
        cout << 1 << endl;
        return;
    }

    dd avg = (c + h) / 2.0;
    if (t <= avg) {
        cout << 2 << endl;
        return;
    }

    dd x = (h-t)/(t*2 - h - c);
    
    ll ans1 = floor(x), ans2 = ceil(x);

    ll ans = abs((c*ans1+h*(ans1+1))/(2.0*ans1+1) - t) <= abs((c*ans2+h*(ans2+1))/(2.0*ans2+1) - t) ? ans1 : ans2;

    cout << ans*2+1 << endl;

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
