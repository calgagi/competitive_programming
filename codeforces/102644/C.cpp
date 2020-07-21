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
#define v vector

const ll MOD = 1e9+7;

v<v<ll>> mult(v<v<ll>> a, v<v<ll>> b) {
    v<v<ll>> ans = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
                
    return ans;
}

void solve() {
    ll n;
    cin >> n;

    v<v<ll>> A = {{0, 1}, {1, 1}};
    v<v<ll>> ans = {{1, 0}, {0, 1}};

    while (n) {
        if ((n & 1)) {
            ans = mult(ans, A);
        }
        n >>= 1;
        A = mult(A, A);
    }

    cout << ans[1][0] << endl;

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
