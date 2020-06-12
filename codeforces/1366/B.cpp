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
    int n, x, m;
    cin >> n >> x >> m;

    int high = x, low = x;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        if (l <= high) {
            high = max(r, high);
        }
        if (r >= low) {
            low = min(l, low);
        }
    }

    cout << high-low+1 << endl;

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
