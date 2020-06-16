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

    int count[2] = {0};
    for (int& x : a) {
        x &= 1; 
        count[x]++;
    }

    if (!(count[0]-count[1] >= 0 && count[0]-count[1] <= 1)) {
        cout << -1 << endl;
        return;
    } 

    int need = 0;
    for (int i = 0; i < n; i++) {
        if ((i & 1) != a[i]) {
            need++;
        }
    }

    cout << need/2 << endl;

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
