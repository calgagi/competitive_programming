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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> need(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > i+1) {
            cout << -1 << endl;
            return;
        }     
        need[a[i]]++;
    }
    
    vector<int> ans(n, -1);
    int MIN = 0, MAX = 0;

    for (int i = 0; i < n; i++) {
        while (MAX < n && need[MAX]) {
            MAX++;
        }
        if (need[MIN]) {
            ans[i] = MAX;
            if (MAX < n) {
                MAX++;
            }
        } else {
            ans[i] = MIN;
            while (!need[MIN] && MIN <= MAX) {
                MIN++;
            }
            MAX = max(MAX, MIN);
        }
        need[a[i]]--;
    }

    vector<bool> seen(n+1, 0);
    for (int i = 0, j = 0; i < n; i++) {
        seen[ans[i]] = 1;
        while (j < n && seen[j]) {
            j++;
        }
        if (j != a[i]) {
            cout << -1 << endl;
            return;
        }
    }

    for (int& x : ans) {
        cout << x << " ";
    }
    cout << endl;

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
