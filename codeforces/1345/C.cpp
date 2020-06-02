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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
        if (x < 0) {
            x %= n;
            x += n;
        }
    } 

    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        used[(i+a[i]) % n]++;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] != 1) {
            cout << "NO" << endl;
            return;
        }
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
