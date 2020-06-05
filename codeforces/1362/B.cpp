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
    for (int& x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    for (int i = 1; i <= 1024; i++) {
        vector<int> test(n);
        for (int j = 0; j < n; j++) {
            test[j] = a[j] ^ i;
        }
        sort(test.begin(), test.end());
        bool good = 1;
        for (int j = 0; j < n; j++) {
            if (test[j] != a[j]) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
        
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
