// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int a, b; cin >> a >> b;

    int diff = abs(a - b), ans = 0;
    while (ans*(ans+1)/2 < diff || ((b+a+(ans*(ans+1)/2)) & 1) == 1) ans++;
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());


    int t; cin >> t;
    while (t--) solve();

    return 0;
}
