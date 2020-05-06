/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX_N = 20;
int n;
bool adj[MAX_N][MAX_N];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    bool tri[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (adj[i][k] && adj[j][k] && adj[i][j]) {
                    tri[i] = tri[j] = tri[k] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!tri[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    while (1) {
        cin >> n;
        if (n == -1) {
            break;
        }
        solve();
    }

    return 0;
}
