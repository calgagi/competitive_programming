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

const int MAX_N = 5005;
const ll DEFAULT_VAL = -1e9-7;
ar<ll,2> dp[MAX_N][MAX_N][2];
ll a[MAX_N];

const ar<ll,2> comp = {DEFAULT_VAL,DEFAULT_VAL};

ar<ll,2> recurse(int i, int j, bool turn) {
    if (i > j) {
        return {0, 0};
    }
    if (dp[i][j][turn] != comp) {
        return dp[i][j][turn];
    }

    ar<ll,2> left = recurse(i+1, j, !turn);
    ar<ll,2> right = recurse(i, j-1, !turn);
    left[turn] += a[i];
    right[turn] += a[j];
    dp[i][j][turn] = (left[turn] > right[turn] ? left : right);

    return dp[i][j][turn];
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dp[i][j][0] = dp[i][j][1] = comp;
        }
    }

    ar<ll,2> ans = recurse(0, n-1, 0);

    cout << ans[0] << endl;

    return 0;
}
