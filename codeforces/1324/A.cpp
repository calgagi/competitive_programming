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
        int n;
        cin >> n;
        vector<int> c(n);
        for (auto& x : c) {
            cin >> x;
        }
        bool good = 1;
        for (int i = 1; i < n; i++) {
            if ((c[i-1]&1) != (c[i]&1)) {
                good = 0;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}
