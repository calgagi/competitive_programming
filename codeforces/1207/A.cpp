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

    int t; cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        long r = 0;
        if (h > c) {
            int x = min(b/2, p);
            b -= x*2;
            r += x * h;
            r += min(b/2, f) * c;
        } else {
            int x = min(b/2, f);
            b -= x*2;
            r += x * c;
            r += min(b/2, p) * h;
        }
        cout << r << endl;
    }

    return 0;
}
