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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < k && i < n && a[i] < b[i]; i++) {
        swap(a[i], b[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }

    cout << ans << endl;

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
