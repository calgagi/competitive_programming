// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;

int dp[MAX_N][MAX_N][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<int> p(n);
    for (auto& x : p) {
        cin >> x; 
        if (x != 0 && (x&1)) x = 1;
        else if (x != 0) x = 2;
    }

    // Fill with large vals
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j][0] = dp[i][j][1] = 100000;
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i][0] = dp[0][i][1] = 0;
    } 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n+1)/2; j++) {
            if (p[i-1] == 0) {
                dp[i][j][0] = min(dp[i][j] 
            } else {

            }
        }
    }  
            
            
             

    return 0;
}
