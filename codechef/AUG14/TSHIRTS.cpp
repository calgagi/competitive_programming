/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const int M = 1e9+7, MAX_T = 101, MAX_N = 10;

void solve() {
    int n;
    cin >> n;
    string g;
    getline(cin, g);

    vector<vector<int>> pt(MAX_T);

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        istringstream in(s);
        int x;
        while (in >> x) {
            pt[x].push_back(i);
        }
    }

    vector<int> dp((1 << n), 0);
    dp[0] = 1;
    for (int tshirt = 0; tshirt < MAX_T; tshirt++) {
        vector<int> new_dp = dp;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int person : pt[tshirt]) {
                if (!((1 << person) & mask)) {
                    new_dp[mask | (1 << person)] = (new_dp[mask | (1 << person)] + dp[mask]) % M;
                }
            }
        }
        dp = new_dp;
    }

    cout << dp[(1 << n)-1] << endl;

    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
