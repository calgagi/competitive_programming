// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;


string solve() {
    int n; 
    cin >> n;
    int s = 0;
    bool odd = false, even = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        if (x % 2 == 1) {
            odd = true;
        } else {
            even = true;
        }
    }
    if (odd && even) return "YES";
    if (odd && n % 2 == 1) return "YES";
    return "NO"; 
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;

    return 0;
}
