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
    
    int n, x;
    cin >> n >> x;
    vector<ii> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> books[i].second;
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - books[i-1].first >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-books[i-1].first] + books[i-1].second);
            }
            dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            /* cout << dp[i][j] << " "; */
        }
        /* cout << endl; */
    }

    cout << dp[n][x] << endl;

    return 0;
}
