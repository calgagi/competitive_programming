/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define f first
#define s second

void solve() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int& x : a) {
        cin >> x; 
    }
    for (int& x : b) {
        cin >> x;
    }

    map<int, int> seen;

    for (int i = 0; i < n; i++) {
        seen[a[i]]++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (seen[b[i]] != 0) {
            ans = min(ans, b[i]);
        }
    }

    if (ans == INT_MAX) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << 1 << " " << ans << endl;
    }

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
