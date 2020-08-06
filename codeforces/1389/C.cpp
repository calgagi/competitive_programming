/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    int ans = 0;
    for (int first = 0; first <= 9; first++) {
        for (int second = 0; second <= 9; second++) {
            int count = 0;
            bool start = 0;
            for (int i = 0; i < n; i++) {
                if (!start && s[i] == '0' + first) {
                   start = 1;
                } else if (start && s[i] == '0' + second) {
                   start = 0;
                   count++;
                }
            }

            count *= 2;
            if (start && first == second) {
                count++;
            }
                
            ans = max(count, ans);
        }
    }

    cout << n - ans << endl;
    
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
