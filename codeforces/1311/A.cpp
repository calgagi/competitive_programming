// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int moves = 0;
        if (a == b) {
            moves = 0;
        } else if (a > b) {
            if (a % 2 != b % 2) {
                moves = 2;
            } else {
                moves = 1;
            }
        } else if (a < b) {
            if (a % 2 != b % 2) {
                moves = 1;
            } else {
                moves = 2;
            }
        }

        cout << moves << endl;
    }

    return 0;
}
