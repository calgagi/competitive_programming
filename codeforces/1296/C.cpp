// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;


void solve() {
    map<int,map<int,int>> h;
    int n;
    cin >> n;
    string m;
    cin >> m;
    
    int l = 1, r = INT_MAX, x = 0, y = 0;
    h[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (m[i] == 'L') {
            x--;
        } else if (m[i] == 'R') {
            x++;
        } else if (m[i] == 'U') {
            y++;
        } else if (m[i] == 'D') {
            y--;
        }
        if (h.find(x) != h.end() && h[x].find(y) != h[x].end()) {
            if (r-l+1 > (i+1)-h[x][y]+1) {
                r = i+1;
                l = h[x][y];
            }
        } 
        h[x][y] = i+2;
    }
    if (r-l+1 == INT_MAX) {
        cout << -1 << endl;
        return;
    }
    cout << l << " " << r << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
