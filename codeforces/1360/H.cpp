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

int under(const string& a, const string& b) {
    for (int i = 0; i < (int) min(a.length(), b.length()); i++) {
        if (a[i] < b[i]) {
            return i;
        } else if (a[i] > b[i]) {
            return -1;
        }
    }
    return -1;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (string& x : s) {
        cin >> x;
    }

    string ans = "";
    ll left = 0, k = (1LL << m) - n;
    ll target = (k-1)/2LL;
    for (int i = 0; i < m; i++) {
        string ans0 = ans + "0", ans1 = ans + "1";
        ll left1 = left + (1LL << (m-1-i));
        for (string& x : s) {
            left1 -= under(x, ans1) == i;
        }
        if (target >= left1) {
            ans = ans1;
            left = left1;
        } else {
            ans = ans0;
        }
        //cout << ans << endl;
    } 

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
