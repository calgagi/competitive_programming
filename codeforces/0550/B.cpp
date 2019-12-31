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
    int l, r, x; cin >> l >> r >> x;
    vector<int> c(n);
    for (auto& i : c) cin >> i;

    sort(c.begin(), c.end());

    set<int> seen;
    
    queue<int> q;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            q.push((1 << i) | (1 << j));

    long long ans = 0;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        if (seen.find(s) != seen.end())
            continue;
        seen.insert(s);
        // Get total
        int cur = 0, mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & s) {
                cur += c[i];
                mn = min(mn, c[i]);
                mx = max(mx, c[i]);
            }
        }
        if (cur <= r && cur >= l && mx-mn >= x) 
            ans++;
        else if (cur > r)
            continue;
        for (int  i = 0; i < n; i++) {
            if (((1 << i) & s) == 0 && c[i] + cur <= r && seen.find((1 << i) | s) == seen.end()) {
                q.push((1 << i) | s);
            } else if (c[i] + cur > r) {
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
