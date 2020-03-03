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
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    ll res = 1;
    if (n > m) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            res = (res * abs(a[j]-a[i])) % m;
        }
    }

    cout << res << endl;

    return 0;
}
