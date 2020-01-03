// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    // n^2 / 2 dp
    int n; cin >> n;
    vector<int> b(n);
    for (auto& B : b) cin >> B;

    vector<int> s = b;
    map<int,int> m;
    sort(s.begin(), s.end());
    int counter = 0;
    m[s[0]] = counter++;
    for (int i = 1; i < n; i++) {
        if (s[i-1] != s[i]) {
            m[s[i]] = counter++;
        }
    }
    for (auto& i : b) i = m[i];

    vector<vector<int>> dp(n, vector<int>((int)m.size(), 1));

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][b[j]] = max(dp[i][b[j]], dp[j][b[i]]+1);            
            ans = max(ans, dp[i][b[j]]);
        }
    }
    cout << ans << endl;
            

    return 0;
}
