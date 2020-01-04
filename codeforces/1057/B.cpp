// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<int> r(n);
    for (auto& R : r) cin >> R;

    // easy n^2
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tot = 0;
        for (int j = i; j < n; j++) {
            tot += r[j];
            if (100 * (j - i + 1) < tot) 
                ans = max(ans, (j - i + 1));
        }
    }
    cout << ans << endl;
    

    return 0;
}
