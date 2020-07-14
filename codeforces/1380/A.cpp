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

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (a[j] > a[i]) {
            for (int k = j+1; k < n; k++) {
                if (a[j] > a[k]) {
                    cout << "YES" << endl;
                    cout << i+1 << " " << j+1 << " " << k+1 << endl;
                    return;
                }
            }
        } else {
            i = j;
        }
    }

    cout << "NO" << endl;

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
