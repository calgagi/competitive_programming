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

    if (n == 1 || m == 1) {
        cout << "YES" << endl;
        return;
    }  
    if (n == 2 && m == 2) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

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
