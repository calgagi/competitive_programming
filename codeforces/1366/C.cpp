/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = 0;

    // look at diags
    /* cout << "START" << endl; */
    for (int i = 0; i < (n+m-1)/2; i++) {
        vector<int> counts(2, 0);
        int row = min(i, n-1), col = max(0, i-(n-1));
        /* cout << row << " " << col << endl; */
        for (; row >= 0 && col >= 0 && row < n && col < m; col++, row--) {
            counts[mat[row][col]]++;
        }
        int j = (n+m-1) - (i+1);
        row = min(j, n-1), col = max(0, j-(n-1));
        /* cout << row << " " << col << endl; */
        for (; row >= 0 && col >= 0 && row < n && col < m; col++, row--) {
            counts[mat[row][col]]++;
        }
        ans += min(counts[0], counts[1]); 
    }
      
    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
