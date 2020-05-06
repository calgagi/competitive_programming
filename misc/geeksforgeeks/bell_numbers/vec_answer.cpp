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
    
    int dp[MAX_N];
    memset(dp, 255, sizeof(dp));
    
    vector<int> prev = {1};
    dp[1] = 1;
    
    for (int i = 2; i < MAX_N; i++) {
        vector<int> cur = {prev.back()};
        for (int j = 0; j < (int) prev.size(); j++) {
            cur.push_back(add(cur.back(), prev[j]));
        }
        dp[i] = cur.back();
        prev = cur;
    }
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}

