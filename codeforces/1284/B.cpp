// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int MX_i = 1e6 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<int> amx, ami;
    for (int i = 0; i < n; i++) {
        int sz; cin >> sz;
        int mi = INT_MAX, mx = INT_MIN, prev = INT_MAX;
        bool decreasing = true; 
        for (int j = 0; j < sz; j++) {
            int s; cin >> s;
            mi = min(mi, s);
            mx = max(mx, s);
            if (prev < s) decreasing = false;
            prev = s;
        }
        if (decreasing) {
            ami.push_back(mi);
            amx.push_back(mx);
        }
    }
    sort(amx.begin(), amx.end());

    long long ans = (n * 1LL * n);
    for (auto& minimum : ami) {
        int l = 0, r = amx.size()-1; 
        int index = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (amx[m] <= minimum) {
                index = max(index, m);
                l = m+1;
            } else {
                r = m-1;
            }
        }
        ans -= index+1;
    }

    cout << ans << endl;

    return 0;
}
