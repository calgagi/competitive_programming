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
    

    string s, t, u;
    int a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> u;
    if (u == t) {
        b--;
    } else if (u == s) {
        a--;
    }
    
    cout << a << " " << b << endl;

    return 0;
}
