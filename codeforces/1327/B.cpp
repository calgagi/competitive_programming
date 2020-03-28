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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> l(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        l[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> l[i][j];
            l[i][j]--;
        }
    }
    vector<bool> used(n, 0);
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < (int) l[i].size() && used[l[i][j]]) {
            j++;
        }
        if (j < (int) l[i].size()) {
            used[l[i][j]] = 1;
        } else {
            idx = i;
        }
    }
    if (idx == -1) {
        cout << "OPTIMAL" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << "IMPROVE" << endl << idx+1 << " " << i+1 << endl;
            return;
        }
    }
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
