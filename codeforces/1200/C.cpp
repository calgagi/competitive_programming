// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

ull gcd(ull a, ull b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q; cin >> n >> m >> q;
    ll d = gcd(n, m);
    ll s1 = n / d, s2 = m / d;
    for (ll x = 0; x < q; x++) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--; ey--;
        if (sx == 1) sy /= s1;
        else sy /= s2;
        if (ex == 1) ey /= s1;
        else ey /= s2;
        if (sy == ey) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
