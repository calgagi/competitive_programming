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
    ll a, b;
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    if (a*2LL < b) {
        cout << "NO" << endl;
        return;
    }

    if ((a+b) % 3 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

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
