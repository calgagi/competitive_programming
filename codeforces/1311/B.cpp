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
    vector<int> a(n), p(n, 0);
    set<int> s;
    for (auto& i : a) {
        cin >> i;
    }
    for (int i = 0; i < m; i++) {
        int j;
        cin >> j;
        j--;
        p[j] = 1;
    }
    
    /* cout << "BEGIN" << endl; */
    /* cout << "p: "; */
    /* for (auto& i : p) { */
    /*     cout << i << " "; */
    /* } */
    /* cout << endl; */
    vector<int> b = a;
    sort(b.begin(), b.end());
    int i = 0;
    for (i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            // Find where it is
            /* cout << i << " "; */
            int j = 1;
            bool f = 0;
            for (j = 1; i+j < n || i-j >= 0; j++) {
                if (i+j < n && b[i+j] == a[i]) {
                    j = i+j;
                    f = 1;
                    break;
                } else if (i-j >= 0 && b[i-j] == a[i]) {
                    j = i-j;
                    f = 1;
                    break;
                }
            }
            /* cout << j << endl; */
            // Test if swappable
            for (int k = min(j,i); k < max(j,i); k++) {
                if (p[k] == 0) {
                    /* cout << "found: " << k << endl; */
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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
