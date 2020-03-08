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
        ll x, y, b;
        cin >> y >> x;
        b = max(x,y);
        ll mx = b*b;
        if (x < y) {
            if ((b&1)) {
                mx -= y+(b-x);
            } else {
                mx -= x;
            } 
        } else {
            if ((b&1)) {
                mx -= y;
            } else {
                mx -= x+(b-y);
            } 
        }        
        cout << mx+1 << endl;
    }

    return 0;
}
