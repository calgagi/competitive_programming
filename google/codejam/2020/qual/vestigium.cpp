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
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (auto& r : m) {
        for (auto& c : r) {
            cin >> c;
        }
    }
    
    int tr = 0;
    for (int i = 0; i < n; i++) {
        tr += m[i][i];
    }

    int rr = 0;
    for (int i = 0; i < n; i++) {
        vector<int> c(n+1, 0);
        for (int j = 0; j < n; j++) {
            c[m[i][j]]++;
            if (c[m[i][j]] > 1) {
                rr++;
                break;
            }
        }
    }

    int rc = 0;
    for (int i = 0; i < n; i++) {
        vector<int> c(n+1, 0);
        for (int j = 0; j < n; j++) {
            c[m[j][i]]++;
            if (c[m[j][i]] > 1) {
                rc++;
                break;
            }
        }
    }

    cout << tr << " " << rr << " " << rc << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
