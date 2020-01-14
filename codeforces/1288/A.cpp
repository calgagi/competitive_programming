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

    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        int x = (int) sqrt(d);
        bool good = false;
        for (int i = 0; i <= x; i++) {
            int a = (d / (i+1)) + (d%(i+1)!=0?1:0), b = i;
            if (a + b <= n) {
                good =true;
                break;
            }
        }
        cout << (good?"YES":"NO") << endl;
    }
        
     

    return 0;
}
