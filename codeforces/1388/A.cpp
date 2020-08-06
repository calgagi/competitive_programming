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

    if (n > 30) {
        cout << "YES" << endl;
        n -= 2*3 + 2*5;
        cout << 2*3 << " " << 2*5 << " ";
        if (n - 14 == 14 || n - 14 == 6 || n - 14 == 10) {
            cout << 15 << " ";
            n -= 15;
        } else {
            cout << 14 << " ";
            n -= 14;
        }
        cout << n << endl;
    } else {
        cout << "NO" << endl;
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
