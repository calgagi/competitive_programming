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

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (ll& a : A) {
        cin >> a;
    }

    vector<vector<pair<ll,ll>>> dp(N+1, vector<pair<ll,ll>>(N+1));
    for (int i = 0; i < N; i++) {
        dp[i][1] = ((N & 1) ? make_pair(A[i], 0LL) : make_pair(0LL, A[i]));
    }

    bool turn = !(N & 1);
    for (int length = 2; length <= N; length++) {
        for (int i = length; i <= N; i++) {
            if (!turn) {
                if (dp[length-1][i].s + A[i-length] < dp[length-1][i-1].s + A[i-1]) {
                    dp[length][i] = dp[length-1][i-1];
                    dp[length][i].s += A[i-1];
                } else {
                    dp[length][i] = dp[length-1][i];
                    dp[length][i].s += A[i-length];
                }
            } else {
                if (dp[length-1][i].f + A[i-length] < dp[length-1][i-1].f + A[i-1]) {
                    dp[length][i] = dp[length-1][i-1];
                    dp[length][i].f += A[i-1];
                } else {
                    dp[length][i] = dp[length-1][i];
                    dp[length][i].f += A[i-length];
                }
            }
        }
        turn = !turn;
    }

    cout << dp[N][N].f << endl;
        
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
