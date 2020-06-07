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
    string s;
    cin >> s;

    int n = s.length();
    
    string ans = "";
    bool one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        ans += '0';
        ans += '1';
        if (s[i] == '0') {
            zero = 1;
        } else {
            one = 1;
        }
    }

    if (!zero || !one) {
        cout << s << endl;
    } else {
        cout << ans << endl;
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
