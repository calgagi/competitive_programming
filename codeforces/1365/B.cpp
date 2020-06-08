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
    vector<ii> a(n);
    for (ii& x : a) {
        cin >> x.f;
    }
    for (ii& x : a) {
        cin >> x.s;
    }

    bool v[2] = {0}, out_of_order = 0;
    for (int i = 0; i < n; i++) {
        v[a[i].s] = 1;
        if (i && a[i].f < a[i-1].f) {
            out_of_order = 1;
        }
    }

    if (out_of_order && (!v[0] || !v[1])) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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
