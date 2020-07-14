/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long, long>
#define ar array
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int change = 0, def = 1e9+7;

    vector<vector<int>> dp(n, vector<int>(6, def));
    dp[0] = {def, 0, 0, 0, 0, def};

    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) {
            int mn = def;
            for (int j = 0; j < 5; j++) {
                dp[i][j] = mn;
                mn = min(mn, dp[i-1][j]);
            }
        } else if (a[i-1] > a[i]) {
            int mn = def;
            for (int j = 5; j > 0; j--) {
                dp[i][j] = mn;
                mn = min(mn, dp[i-1][j]);
            }
        } else {
            dp[i] = dp[i-1];
        }
        int mn = def;
        for (int j = 1; j <= 4; j++) {
            mn = min(mn, dp[i-1][j]);
        }
        for (int j = 1; j <= 4; j++) {
            dp[i][j] = min(mn+1, dp[i][j]);
        }
    }

    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j <= 5; j++) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
        
    cout << min({dp[n-1][4], dp[n-1][1], dp[n-1][2], dp[n-1][3]}) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
