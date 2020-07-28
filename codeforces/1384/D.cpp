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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int bit = 31; bit >= 0; bit--) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if ((a[i] & (1 << bit))) {
                count++;
            }
        }

        if ((count & 1)) {
            if (count % 4 == 3 && (n - count) % 2 == 0) {
                cout << "LOSE" << endl;
                return;
            }
            cout << "WIN" << endl;
            return;
        }
    }

    cout << "DRAW" << endl;

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
