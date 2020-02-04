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
    vector<int> a(n);
    vector<bool> l(n, 0), r(n, 0);
    for (auto& i : a) {
        cin >> i;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= i) {
            l[i] = 1;
        } else {
            break;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if (a[i] >= n-1-i) {
            r[i] = 1;
        } else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (l[i] && r[i]) {
            return "Yes";
        }
    }
    return "No";
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    // Find if there is an item that is larger than length-i and i
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;

    return 0;
}
