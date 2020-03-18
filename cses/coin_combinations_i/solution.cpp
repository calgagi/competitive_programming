// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    const int MOD = 1e9 + 7;
    
    int x, n;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto& c : coins) {
        cin >> c;
    }

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto& c : coins) {
            dp[i] = (dp[i] + (i-c >= 0 ? dp[i-c] : 0)) % MOD;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
