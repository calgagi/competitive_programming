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

    const int MAX = 1e9;
    
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto& c : coins) {
        cin >> c;
    }
    vector<int> dp(x+1, MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (auto& c : coins) {
            dp[i] = min(dp[i], (i-c >= 0 ? dp[i-c]+1 : MAX));
        }
    }

    cout << (dp[x] == MAX ? -1 : dp[x]) << endl;

    return 0;
}
