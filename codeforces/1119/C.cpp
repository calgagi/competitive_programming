// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 500;
int a[MAX+1][MAX+1], b[MAX+1][MAX+1];

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 


    int m, n;
    cin >> m >> n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int ar = 0, br = 0;
        for (int j = 0; j < n; j++) {
            ar += a[i][j];
            br += b[i][j];
        }
        if ((ar&1) != (br&1)) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int j = 0; j < n; j++) {
        int ac = 0, bc = 0;
        for (int i = 0; i < m; i++) {
            ac += a[i][j];
            bc += b[i][j];
        }
        if ((bc&1) != (ac&1)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
