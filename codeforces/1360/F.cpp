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
 
vector<string> s;
int n, m;
 
bool test(const string& t) {
    for (int i = 0; i < n; i++) {
        int diff = 0;
        for (int j = 0; j < m; j++) {
            if (t[j] != s[i][j]) {
                diff++;
            }
        }
        if (diff > 1) {
            return 0;
        }
    }
    return 1;
}
 
void solve() {
    cin >> n >> m;
    s.resize(n);
    for (string& x : s) {
        cin >> x;
    }
 
    string ans = s[0];
    if (test(ans)) {
        cout << ans << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != ans[j]) {
                char x = s[i][j];
                swap(x, ans[j]);
                if (test(ans)) {
                    cout << ans << endl;
                    return;
                }
                swap(ans[j], x);
            }
        }
    }
 
    cout << -1 << endl;
 
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
