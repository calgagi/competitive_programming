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

    int bin_digits = n / 4;
    bool remove_1 = n % 4;

    for (int i = 0; i < n - bin_digits - remove_1; i++) {
        cout << 9;
    }
    
    for (int i = 0; i < bin_digits + remove_1; i++) {
        cout << 8;
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
