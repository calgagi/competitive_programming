// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n; cin >> n;
    vector<long long> a(n);
    long long y = 0;
    for (auto& i : a) {
        cin >> i;
        y += i;
    }
    // Find if a max subarray has greater sum than y
    vector<long long> dp1(n-1, LONG_MIN), dp2(n-1, LONG_MIN);
    dp1[0] = a[0], dp2[0] = a[1];
    for (int i = 1; i < n-1; i++) {
        dp1[i] = max(a[i], dp1[i-1] + a[i]);
        dp2[i] = max(a[i+1], dp2[i-1] + a[i+1]);
    }

    for (int i = 0; i < n-1; i++) {
        if (dp1[i] >= y || dp2[i] >= y) {
            cout << "NO" << endl;
            return 0;
        }
    } 

    cout << "YES" << endl;
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
