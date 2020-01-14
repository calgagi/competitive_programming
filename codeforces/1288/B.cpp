// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

void solve() {
    ll a, b, ans = 0;
    cin >> a >> b;
    
    ll c = 9;
    while (c <= b) {
        ans += a;
        c = (c*10LL) + 9LL;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    int t; cin >> t;
    while (t--) {
        solve();
    }
     

    return 0;
}
