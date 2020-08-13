/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

int r, g, b, w;
bool palindrome() {
    return (r & 1) + (g & 1) + (b & 1) + (w & 1) <= 1;
}

void solve() {
    cin >> r >> g >> b >> w;

    for (int i = 0; i < 20; i++) {
        if (palindrome()) {
            cout << "Yes" << endl;
            return;
        }
        if (r && g && b) {
            r--, g--, b--;
            w += 3;
        }
    }
        
    cout << "No" << endl;

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
