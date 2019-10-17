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

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);

    ld a, b, c, d, m, t;
    while (true) {
        cin >> a >> b >> c >> d >> m >> t;
        if (cin.fail()) break;
        
        ld l = 0.0, h = (t / m - d) / c;
        for (int i = 0; i < 100; i++) {
            ld v = l + (h-l)/2;
            ld mm = a*v*v*v + b*v*v + c*v + d - t/m;
            if (mm < 0)
                l = v;
            else
                h = v;
        }
        cout << l << endl;
    }
    
             

    return 0;
}
