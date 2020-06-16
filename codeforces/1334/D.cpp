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
    ll n, l, r;
    cin >> n >> l >> r;

    ll neighbors = n-1;
    ll home = 1, where = 1;
    while (where + 2LL*neighbors < l && 2LL*neighbors != 0) {
        where += 2LL*neighbors;
        home++;
        neighbors--;
    }

    for (int i = home; i <= n && where <= r; i++) {
        for (int j = i+1; j <= n && where <= r; j++) {
            if (where >= l && where <= r) {
                cout << i << " ";
            }
            where++;
            if (where >= l && where <= r) {
                cout << j << " ";
            }
            where++;
        }
    }

    if (where <= r) {
        cout << 1 << endl;
    } else {
        cout << endl;
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
