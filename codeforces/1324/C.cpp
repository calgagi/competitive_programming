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
    string s;
    cin >> s;
    s += "R";
    s.insert(s.begin(), 'R');
    int ans = 1, streak = 0, n = s.length();
    for (int i = 0; i < n; i++) {
        streak++;
        ans = max(ans, streak);
        if (s[i] == 'R') {
            streak = 0;
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
