// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 1e4;

int binary_search(int base, int near) {
    int l = 1, r = MAX, res = INT_MAX;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int c = m*base;
        if (abs(near-c) < abs(near-res)) {
            res = c;
        }
        if (c < near) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return res;
}

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    
    // Loop over a = [1, 10^4]
    // Binary search for closest b, c to B and C

    int steps = A-1 + B-1 + C-1, ansa = 1, ansb = 1, ansc = 1;
    for (int a = 1; a <= 2*MAX; a++) {
        for (int b = a; b <= 2*MAX; b += a) {
            int c = binary_search(b, C);
            int prev = steps;
            steps = min(steps, abs(A-a) + abs(B-b) + abs(C-c)); 
            if (steps < prev) {
                ansa = a;
                ansb = b;
                ansc = c;
            } 
        }
    }

    cout << steps << endl;
    cout << ansa << " " << ansb << " " << ansc << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
