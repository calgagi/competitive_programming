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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    bool all_zero = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] %= x;
        if (a[i]) {
            all_zero = 0;
        }
        sum += a[i];
    }

    if (all_zero) {
        cout << -1 << endl;
        return;
    }

    if (sum % x != 0) {
        cout << n << endl;
        return;
    }

    int ans_left = 0, ans_right = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            ans_left = n-i-1;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (a[i] != 0) {
            ans_right = i;
            break;
        }
    }

    cout << max({1, ans_left, ans_right}) << endl;

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
