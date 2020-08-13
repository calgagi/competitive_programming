/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

int n, m, sx, sy;

void solve() {
    cin >> n >> m >> sx >> sy;
    sx--, sy--;

    vector<pair<int,int>> ans = {{sx, sy}};
    for (int i = 0; i < m; i++) {
        if (sy == i) {
            continue;
        }
        ans.push_back({sx, i});
    }

    bool dir = 0;
    for (int i = 0; i < n; i++) {
        if (i == sx) {
            continue;
        }
        dir = !dir;
        for (int j = 0; j < m; j++) {
            ans.push_back({i, (dir ? m-j-1 : j)});
        }
    }
                
    for (pair<int,int>& coord : ans) {
        cout << coord.first+1 << " " << coord.second+1 << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
