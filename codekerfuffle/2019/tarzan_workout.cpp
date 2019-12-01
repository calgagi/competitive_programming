// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        int t = 0;
        vector<int> m; m.push_back(0);
        for (int j = 0; j < s; j++) {
            int x; cin >> x;
            m.push_back(x);
            t += x;
        }
        int d = 1000;
        vector<vector<int>> dp(m.size(), vector<int>(2+(t/2), d));
        dp[0][0] = 0;
        for (int j = 1; j < dp.size(); j++) {
            for (int k = 0; k < dp[0].size(); k++) {
                if (k-m[j] >= 0 && dp[j-1][k-m[j]] != d)
                    dp[j][k] = min(dp[j-1][k-m[j]]+m[j], max(k, dp[j-1][k-m[j]]));
                if (k+m[j] < dp[0].size() && dp[j-1][k+m[j]] != d)
                    dp[j][k] = min(dp[j-1][k+m[j]], dp[j][k]);
            }
        }
        if (dp.back()[0] == d) cout << "IMPOSSIBLE" << endl;
        else cout << dp.back()[0] << endl;
    }


    return 0;
}
