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
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    // n0
    string ans = "";
    if (n0) {
        ans += "00";
    }
    for (int i = 2; i <= n0; i++) {
        ans += "0";
    }

    // n2
    if (n2) {
        ans += "11";
        if (n0) {
            n1--;
        }
    }
    for (int i = 2; i <= n2; i++) {
        ans += "1";
    }

    // n1
    if (n1) {
        if (ans != "" && ans.back() == '1') {
            ans += "0";
        } else if (ans != "" && ans.back() == '0') {
            ans += "1";
        } else {
            ans += "01";
        }
        n1--;
    }
    for (int i = 1; i <= n1; i++) {
        ans += (ans.back() == '1' ? '0' : '1');
    }

    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
