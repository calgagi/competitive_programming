/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> ans(n+1, "");
    for (int i = 0; i < 200; i++) {
        ans[0] += 'a';
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            ans[i+1] += ans[i][j];
        }
        char x = ans[i][a[i]];
        int y = x - 'a';
        y++;
        y %= 26;
        x = 'a' + y;
        for (int k = ans[i+1].length(); k < 200; k++) {
            ans[i+1] += x;
        }
    }

    for (string& x : ans) {
        cout << x << endl;
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
