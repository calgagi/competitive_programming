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

    int n, a;
    cin >> n >> a;
    int l, ln, rn, r, b;
    r = INT_MIN, l = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (l > b) {
            ln = min(l, ln);
            l = b;
        } else if (ln > b) {
            ln = b;
        }
        if (r < b) {
            rn = max(r, rn);
            r = b;
        } else if (rn < b) {
            rn = b;
        }
    }
    if (a < l)
        cout << rn - a << endl;
    else if (a > r)
        cout << ln - a << endl;
    else {
        int lf = 2*abs(a - ln) + r;
        int rf = 2*abs(a - rn) + l;
        cout << min(lf, rf) << endl;
    }


    return 0;
}
