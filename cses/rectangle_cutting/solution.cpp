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

const int M = 500;
int dp[M+1][M+1];

int dfs(int a, int b) {
    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    dp[a][b] = a*b;
    for (int i = 1; i <= min(a, b); i++) {
        dp[a][b] = min({dp[a][b], 
                        1 + dfs(a - i, b - i) + dfs(a - i, i) + dfs(i, b - i), 
                        1 + dfs(a - i, b) + dfs(i, b - i), 
                        1 + dfs(a - i, i) + dfs(a, b - i)}); 
    }
    return dp[a][b];
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    memset(dp, 255, sizeof(dp));
    int a, b;
    cin >> a >> b;

    dp[0][0] = 0;

    cout << dfs(a, b) << endl;

    return 0;
}
