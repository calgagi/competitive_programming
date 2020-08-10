/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> conv(n);
    for (string& s : conv) {
        cin >> s;
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (conv[i][m-1] == 'R') {
            ans++;
        }
    }
    for (int i = 0; i < m-1; i++) {
        if (conv[n-1][i] == 'D') {
            ans++;
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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
