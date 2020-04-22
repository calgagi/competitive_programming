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

const int MAX = 500;
int dp[MAX+1][MAX+1] = {0};

int dfs(int a, int b) {
    if (b < a) {
        swap(a, b);
    }
    if (dp[a][b] != 0) {
        return dp[a][b];
    }    
    if (!a || !b) {
        return 0;
    }
    if (a == b) {
        dp[a][b] = 1;
    } else {
        dp[a][b] = 1e9;
        for (int i = 1; i <= a; i++) {
            dp[a][b] = min({dp[a][b], 1+dfs(a-i,b)+dfs(b-i,i), 1+dfs(b-i,a)+dfs(a-i,i)});
        }
        //cout << a << "," << b << ": " << dp[a][b] << endl;
    }
    return dp[a][b];
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int a, b;
    cin >> a >> b;

    int ans = dfs(a, b);
    cout << ans-1 << endl;

    return 0;
}
