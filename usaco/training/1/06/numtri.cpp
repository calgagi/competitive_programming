/*
ID: calgagi1
LANG: C++
TASK: numtri
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("numtri.in", "r", stdin), *OUT = freopen("numtri.out", "w", stdout); 

    int R;
    cin >> R;
    int tri[R][R];
    memset(tri, 0, sizeof(tri));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
            //cerr << tri[i][j] << " ";
        }
        //cerr << endl;
    }

    int dp[R][R];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = tri[0][0];
    for (int i = 1; i < R; i++) {
        for (int j = 0; j <= i; j++) {
            if (j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+tri[i][j]);
            } 
            if (j != i) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+tri[i][j]);
            }
            //cerr << dp[i][j] << " ";
        }
        //cerr << endl;
    }

    int ans = 0;
    for (int i = 0; i < R; i++) {
        ans = max(ans, dp[R-1][i]);
    } 
    cout << ans << endl;

    return 0;
}
