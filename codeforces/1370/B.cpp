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
    vector<int> a(2*n); 
    for (int i = 0; i < 2*n; i++) { 
        cin >> a[i];
    }

    int odd = -1;
    int operations = n-1;
    for (int i = 0; i < 2*n && operations; i++) {
        if ((a[i] & 1)) {
            if (odd != -1) {
                cout << odd+1 << " " << i+1 << endl;
                operations--;
                odd = -1;
            } 
            else {
                odd = i;
            }
        }
    }

    int even = -1;
    for (int i = 0; i < 2*n && operations; i++) {
        if (!(a[i] & 1)) {
            if (even != -1) {
                cout << even+1 << " " << i+1 << endl;
                operations--;
                even = -1;
            }
            else {
                even = i;
            }
        }
    }

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
