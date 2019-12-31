// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min(a, min(b, min(c/2, min(d/7, e/4)))) << endl;

    return 0;
}
