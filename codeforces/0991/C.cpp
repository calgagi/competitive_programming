// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;


ll check(ll b, ll c) {
    ll r = 0;
    while (b > 0) {
        r += min(c, b);
        b -= c;
        b -= (b / 10);
    } 
    return r;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    ll l = 1, r = n, m;
    ll g = n / 2, k = LLONG_MAX;
    if (n % 2) g++;
    while (l <= r) {
        m = (l+r) / 2;
        ll c = check(n, m);
        if (c < g) l = m+1;
        else if (c >= g) {
            r = m-1;
            k = min(k, m);
        }
    }
    cout << k << endl;
    return 0;
}
