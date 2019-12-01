// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v; cin >> v;
    float x = sqrt(v);
    // Surface area = 2( a*b + a*c + b*c )
    // Two of the values must be less than sqrt(V)
    int m = (int) INFINITY;
    for (int i = 1; i <= (int) x; i++) {
        for (int j = 1; j <= (int) x; j++) {
            float y = (float) v / ((float) i * (float) j);
            if (floor(y) == y)
                m = min(m, 2 * (i*j + i * (int) y + j * (int) y));
        }
    }
    cout << m << endl;
    return 0;
}
