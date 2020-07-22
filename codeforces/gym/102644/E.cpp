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

const ll MOD = (1LL << 32);
const int n = 8;
vector<pii> dir = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

vector<vector<ll>> mult(vector<vector<ll>>& a, vector<vector<ll>>& b, bool add = 0) {
    vector<vector<ll>> ans(n*n, vector<ll>(n*n, 0));

    for (int i = 0; i < n*n; i++) {
        for (int j = 0; j < n*n; j++) {
            for (int k = 0; k < n*n; k++) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }

    return ans;
}

void solve() {
    int k;
    cin >> k;

    vector<vector<ll>> board(n*n, vector<ll>(n*n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            int coord1 = 8*i + j;
            for (pii& d : dir) {
                if (i+d.f < n && i+d.f >= 0 && j+d.s < n && j+d.s >= 0) {
                    int coord2 = coord1 + (d.f*8) + d.s;
                    board[coord1][coord2] = 1;
                }
            }
        }
    }

    vector<vector<ll>> level(n*n, vector<ll>(n*n, 0));
    level[0][0] = 1;
    vector<vector<vector<ll>>> levels; 
    for (ll i = 2; i <= k; i *= 2LL) {
        levels.push_back(mult(levels.back(), levels.back()));
    }

    

    ll num = 0;
    for (int i = 0; i < n*n; i++) {
        for (int j = 0; j < n*n; j++) {
            num += ans[i][j];
            num %= MOD;
        }
    }

    cout << num << endl;

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
