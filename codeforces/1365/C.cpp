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
    vector<int> a(n), b(n);
    for (int& x : a) {
        cin >> x;
    } 
    for (int& x : b) {
        cin >> x;
    }

    vector<int> shift(n+1, 0);
    vector<vector<int>> where(n+1); 

    for (int i = 0; i < n; i++) {
        where[a[i]].push_back(i);
    }
            
    for (int i = 0; i < n; i++) {
        for (int j : where[b[i]]) {
            int s = (j < i ? j+n-i : j-i);
            shift[s]++;
        }
    }
        
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(shift[i], ans);
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
