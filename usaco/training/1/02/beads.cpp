/*
ID: calgagi1
LANG: C++
TASK: beads
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("beads.in", "r", stdin), *OUT = freopen("beads.out", "w", stdout); 

    // N^2 solution is trivial
    // N solution: prefix and suffix DP?
    int n;
    cin >> n;
    string beads;
    cin >> beads;

    beads += beads + beads;
    int best = 0;

    for (int i = 0+n; i < n+n; i++) {
        int left = 0, right = 0;
        for (int j = i-1, b = 0, r = 0; j >= 0 && !(b&&r); j--) { 
            if (beads[j] == 'b') b++;
            else if (beads[j] == 'r') r++;
            if (b&&r) break;
            left = max(left, abs(j-i));
        }
        for (int j = i, b = 0, r = 0; j < n*3 && !(b&&r); j++) {
            if (beads[j] == 'b') b++;
            else if (beads[j] == 'r') r++;
            if (b&&r) break;
            right = max(right, abs(j-i)+1);
        }
        best = max(best, right+left);
    }

    cout << min(best, n) << endl;

    return 0;
}
