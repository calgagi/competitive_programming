// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 101;
int256_t dp[MAX_N];
int last;

void solve() {
    int n;
    cin >> n;
    
    for (int i = last+1; i <= n; i++, last++) {
        for (int j = 0; j <= last; j++) {
            dp[i] += dp[j]*dp[last-j];
        }
    }      

    cout << dp[n] << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    memset(dp, 0, sizeof(dp));
    last = 1;
    dp[0] = dp[1] = 1;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
