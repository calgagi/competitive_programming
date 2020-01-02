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

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> g(n, vector<int>(n, 0));
    
    if ((a == 1 || b == 1) && !((n == 2 || n == 3) && a == 1 && b == 1)) {
        cout << "YES" << endl;
        int c = max(a, b);
        for (int i = 1; i <= n-c; i++) {
            g[i][i-1] = 1;
            g[i-1][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (a == c ? g[i][j] : (g[i][j] == 1 || i == j ? 0 : 1));
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }




    return 0;
}
