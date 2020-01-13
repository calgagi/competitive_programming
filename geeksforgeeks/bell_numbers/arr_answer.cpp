// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

const int MOD = 1e9 + 7;
const int MAX_N = 1010;

int add(int a, int b) {
    return (a + b) % MOD;
}

int main() {
    // Makes cin/cout fast like scanf/printf
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    // Better randomness (hacking from CF)
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // Redirect stdout/in to file(s)
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int dp[MAX_N][MAX_N];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    
    for (int i = 2; i < MAX_N; i++) {
        dp[i][1] = dp[i-1][i-1];
        for (int j = 2; j <= i+1; j++) {
            dp[i][j] = add(dp[i-1][j-1], dp[i][j-1]);
        }
    }
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n][n] << endl;
    }

    return 0;
}

