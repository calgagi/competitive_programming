/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << endl;

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
