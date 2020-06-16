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
    int n, k;
    cin >> n >> k;
    string tables;
    cin >> tables;

    int streak = 0, ans = 0;
    bool first_streak = 1, all_zero = 1;
    for (int i = 0; i < n; i++) {
        if (tables[i] == '0') {
            streak++;
        } else if (tables[i] == '1') {
            all_zero = 0;
            if (first_streak) {
                ans += (streak / (k+1));
                first_streak = 0;
            } else {
                streak -= k;
                ans += max((streak / (k+1)), 0);
            }
            streak = 0;
        }
    }
    ans += (streak / (k+1));

    if (all_zero && streak % (k+1) != 0) {
        ans++;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
