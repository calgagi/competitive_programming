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
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans = "";
        if (n % 2 == 1 && n >= 3) {
            ans += '7';
            n -= 3;
        }
        for (int i = 0; i < n; i += 2)
           ans += '1';
        cout << ans << endl;
    } 
         

    return 0;
}
