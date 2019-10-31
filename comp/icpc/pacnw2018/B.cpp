// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

ull phi(ull n) {
    ull result = n;
    for (ull i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) 
                n /= i;
            result -= n / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
    

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, res = 0;
    cin >> a >> b >> c >> d;
    ull da = phi( 
	

    return 0;
}
