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

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int num_rows = 0, num_cols = 0;

    for (int i = 0; i < n; i++) {
        bool good = 1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                good = 0;
                break;
            }
        }
        if (good) {
            num_rows++;
        }
    }
    for (int j = 0; j < m; j++) {
        bool good = 1;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1) {
                good = 0;
                break;
            }
        }
        if (good) {
            num_cols++;
        }
    }            

    int turns = min(num_rows, num_cols);

    if (!(turns & 1)) {
        cout << "Vivek" << endl;
    } else {
        cout << "Ashish" << endl;
    }

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
