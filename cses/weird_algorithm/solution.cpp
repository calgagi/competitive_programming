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
    
    ll n;
    cin >> n;
    set<ll> seen;
    while (n != 1) {
        if (!seen.count(n)) {
            cout << n << " ";
            seen.insert(n);
        }
        if ((n&1)) {
            n *= 3;
            n++;
        } else {
            n /= 2;
        }
    }
    cout << 1 << endl;

    return 0;
}
