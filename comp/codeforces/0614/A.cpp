// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll l, r, k;
    cin >> l >> r >> k;
    bool x = false;
    for (ll c = 1; 1; c *= k) {
        if (c >= l) { 
            x = true; 
            cout << c << " ";
        }
        if (c > r / k) break;
    }
    if (!x) cout << -1;
    cout << endl;
    return 0;
}
