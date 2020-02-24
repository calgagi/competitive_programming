// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    string s;
    cin >> s;
    for (auto& i : p) {
       cin >> i;
    } 

    vector<int> ans(26, 0), pre(n, 0);
    pre[0] = 1;
    for (int i = 0; i < m; i++) {
        pre[0]++;
        pre[p[i]]--;
    }

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += pre[i];
        ans[s[i]-'a'] += tot;
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << (i == 25 ? "" : " ");
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    // prefix sum array
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
