// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, cl = 0; cin >> n;
    vector<int> a(2*n);
    unordered_map<int,int> m; 
    int diff = 0;
    for (auto& i : a) {
        cin >> i;
        if (i == 2) { i = 0; diff--; }
        else diff++;
    }

    m[0] = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 1) cl++; else cl--;
        if (m.find(cl) == m.end()) m[cl] = n-i;
    } 

    int ans = 2*n;
    if (diff == 0) ans = 0;
    else {
        cl = 0;
        if (m.find(diff) != m.end())
            ans = min(ans, m[diff]);
        for (int i = n; i < 2*n; i++) {
            if (a[i] == 1) cl--; else cl++;
            if (m.find(diff+cl) != m.end()) ans = min(ans, (i-n+1) + m[diff+cl]);
        }
    }


    cout << ans << endl;
}
    


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());


    int t; cin >> t;
    while (t--) solve();

    return 0;
}
