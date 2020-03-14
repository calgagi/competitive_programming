// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int left[n+1] = {0}, right[n+1] = {0};
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        right[x]++;
    }

    for (auto& x : a) {
        right[x]--;
        for (int i = 1; i <= n; i++) {
            if (right[i] && left[i]) {
                cout << "YES" << endl;
                return;
            }
        }
        left[x]++; 
    }
    
    cout << "NO" << endl;
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
