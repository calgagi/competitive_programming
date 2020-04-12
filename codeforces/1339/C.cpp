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

int find_largest_bit(int a) {
    int ans = 0;
    for (int i = 1; i <= 32; i++) {
        if ((a & (1 << (i-1)))) {
            ans = i;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            int d = a[i-1] - a[i];
            ans = max(find_largest_bit(d), ans);
            a[i] = a[i-1];
        }
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
