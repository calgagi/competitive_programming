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
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    
    bool first = 1;
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == 1) {
            first = !first;
        } else {
            break;
        }
    }

    if (i == n) {
        if ((n & 1)) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        cout << (first ? "First" : "Second") << endl;
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
