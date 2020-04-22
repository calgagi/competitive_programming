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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int MX = 1000*100+1;
    bitset<MX> dp;

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        bitset<MX> new_dp;
        for (int j = 0; j < MX; j++) {
            if (dp[j]) {
                new_dp[j+a[i]] = 1;
            }
        }
        dp |= new_dp;
    }

    int ans = 0;
    for (int i = 1; i < MX; i++) {
        if (dp[i] == 1) {
            ans++;
        }
    }

    cout << ans << endl;
    for (int i = 1; i < MX; i++) {
        if (dp[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
