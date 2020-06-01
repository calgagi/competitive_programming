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

    int ans = INT_MAX;

    int oR = 0, oL = 0, zR = 0, zL = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            oR++;
        } else {
            zR++;
        }
    }

    for (int i = 0; i < n; i++) {
        ans = min({ans, zL+oR, oL+zR});
        if (s[i] == '1') {
            oR--;
            oL++;
        } else {
            zR--;
            zL++;
        }
    }
            
    ans = min({ans, zL+oR, oL+zR});

    cout << ans << endl;

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
