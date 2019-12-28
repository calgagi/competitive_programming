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

    int t; cin >> t;
    while (t--) {
        int h, m; cin >> h >> m;
        cout << (23 - h) * 60 + (60 - m) << endl;
    }

    return 0;
}
