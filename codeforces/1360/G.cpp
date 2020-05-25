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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n*a != m*b) {
        cout << "NO" << endl;
        return;
    }

    int shift = 0;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a; j++) {
            mat[i][(j+shift) % m] = 1;
        }
        shift += a;
    }


    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
