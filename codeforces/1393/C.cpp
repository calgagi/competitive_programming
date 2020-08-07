/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    int mx = 0, cnt_mx = 0;
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (mx < cnt[a[i]]) {
            mx = cnt[a[i]];
            cnt_mx = 1;
        } else if (mx == cnt[a[i]]) {
            cnt_mx++;
        }
    }

    /* int ans = (n / (mx - 1)) - cnt_mx - 1; */
    /* cout << max(ans, 0) << endl; */

    int squares = n - (cnt_mx * mx) + mx;
    int ans = 0, left = 1, right = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        int x = 0;
        for (int i = 0; i < squares; i++) {
            if (i % mid == 0) {
                x++;
            }
        }
        if (x >= mx) {
            ans = max(ans, mid-1);
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    cout << ans + (cnt_mx - 1) << endl;

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
