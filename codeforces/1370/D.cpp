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

bool test(vector<int>& a, int m, int k) {
    int n = a.size();

    for (int o = 0; o < 2; o++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (((count & 1) == o) || a[i] <= m) {
                count++;
            }
        }
        if (count >= k) {
            return 1;
        }
    } 
    
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 1, r = 1e9, ans = 1e9;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (test(a, m, k)) {
            r = m-1;
            ans = m;
        } else {
            l = m+1;
        }
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
