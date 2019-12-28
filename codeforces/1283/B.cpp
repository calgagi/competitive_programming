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
        long n, k; cin >> n >> k;
        long a = n / k, b = n % k, c = k / 2;
        cout << a * k + min(b, c) << endl;
    }

    return 0;
}
