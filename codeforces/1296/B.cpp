// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;


int solve() {
    int s;
    cin >> s;
    int ans = 0;
    while (s >= 10) {
        int r = s - (s % 10), a = s % 10;
        int div = r / 10;
        ans += r;
        s = div + a;
    } 
    return ans + s;
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
