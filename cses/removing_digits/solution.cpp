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
    
    int n;
    cin >> n;
    int a = 0;
    while (n) {
        int m = 0, x = n;
        while (x) {
            m = max(m, x % 10);
            x /= 10;
        }
        n -= m;
        a++;
    }
    cout << a << endl;

    return 0;
}
