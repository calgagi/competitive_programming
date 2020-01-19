// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    string s;
    cin >> s;
    int n = s.length();
    int OUTSIDE = 0, INSIDE = 0, ans = 0;
    // +-+-
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            if (INSIDE == 0) ans++;
            else INSIDE--;
            OUTSIDE++;
        } else {
            if (OUTSIDE == 0) ans++;
            else OUTSIDE--;
            INSIDE++;
        }
    }
    cout << ans << endl;

    return 0;
}
