/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

void solve() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int i = 0;
    for (; i < n; i++) {
        b -= a[i];
        if (b < 0) {
           break; 
        }
    } 
    
    cout << i;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
