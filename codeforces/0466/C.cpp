// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<int> a(n);
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i]; 
    }
    if (tot % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    long long val = tot / 3, cur = 0, ans = 0;

    vector<int> cnt(n, 0);
    
    for (int i = n-1; i >= 0; i--) {
        cur += a[i];
        if (cur == val) cnt[i] = 1;
        cnt[i] += (i+1<n?cnt[i+1]:0);
    }

    cur = 0;
    for (int i = 0; i+2 < n; i++) {
        cur += a[i];
        if (cur == val) ans += cnt[i+2];
    }
    cout << ans << endl;
    return 0;
}
