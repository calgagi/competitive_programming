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

    ll r, x, y, xx, yy;
    cin >> r >> x >> y >> xx >> yy;
    // Pythagorean theorem
    ll a;
    ld d = sqrt(pow(xx-x,2)+pow(yy-y,2));
    
    a = d / (2*r);
    if (a * (2*r) < d) a++;
    cout << a << endl;

    return 0;
}
