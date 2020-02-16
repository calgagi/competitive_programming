// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        bool seen1 = false;
        int z = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                seen1 = 1;
            }
            if (seen1 && s[i] == '0') {
                z++;
            } else if (seen1 && s[i] == '1') {
                ans += z;
                z = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
