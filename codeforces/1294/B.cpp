// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;


void solve() {
    int n;
    cin >> n;
    vector<ii> p(n);
    for (auto& i : p) {
        cin >> i.first >> i.second;
    }

    sort(p.begin(), p.end());
    string ans = "";
    ii pos = {0, 0};
    for (auto& package : p) {
        // always want to move right first
        while (pos.first < package.first) {
            ans += 'R';
            pos.first++;
        }
        while (pos.second < package.second) {
            ans += 'U';
            pos.second++;
        }
        if (pos.first != package.first || pos.second != package.second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << ans << endl; 


    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 


    int t;
    cin >> t;
    while (t--) 
        solve();

     

    return 0;
}
