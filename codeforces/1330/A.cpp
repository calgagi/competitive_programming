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
    int n, x;
    cin >> n >> x;
    vector<bool> v(300, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a] = 1;
    }

    int i;
    for (i = 1; v[i] || x; i++) {
        if (v[i] == 0) {
            v[i] = 1;
            x--;
        }
    }

    cout << i-1 << endl;
    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
