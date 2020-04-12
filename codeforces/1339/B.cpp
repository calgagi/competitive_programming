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
    for (auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    vector<int> ans(n);
    if ((n & 1)) {
        ans[n-1] = a[n/2];
    }
    for (int i = 0; i < n/2; i++) {
        ans[i*2] = a[i];
        ans[i*2+1] = a[n-1-i];
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

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
