// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    int l = a+1, r = b;
    while (l <= r) {
        int g = l + (r - l) / 2;
        cout << g << endl;
        fflush(stdout);
        string res;
        cin >> res;
        if (res == "CORRECT") {
            break;
        } else if (res == "TOO_BIG") {
            r = g-1;
        } else if (res == "TOO_SMALL") {
            l = g+1;
        }
    }
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
