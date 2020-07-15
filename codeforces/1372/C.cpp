/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long, long>
#define ar array
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = a[i] == i+1;
    }

    int ans = 0, streak = 0;
    for (int i = 0; i < n; i++) {
        if (!order[i]) {
            streak++;
        } else {
            if (streak) {
                ans++;
                streak = 0;
            }
        }
    }
    if (streak) {
        ans++;
    }

    cout << min(ans, 2) << endl;

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
