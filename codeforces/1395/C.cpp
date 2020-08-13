/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

int n, m;
const int MAX_N = 200;
int a[MAX_N], b[MAX_N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }

    int ans;
    for (ans = 0; ans < (1 << 9); ans++) {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            bool good = 0;
            for (int j = 0; j < m; j++) {
                if ((ans | (a[i] & b[j])) == ans) {
                    good = 1;
                    break;
                }
            }
            if (!good) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            break;
        }
    }

    cout << ans << endl;

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
