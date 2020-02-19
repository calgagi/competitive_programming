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
    
    int s;
    cin >> s;

    vector<ll> group1;
    ll g1 = 0, g2 = 0;
    for (ll i = s; i > 0; i--) {
        if (g1 < g2) {
            g1 += i;
            group1.push_back(i);
        } else {
            g2 += i;
        }
    }
    
    cout << abs(g1 - g2) << endl;
    cout << group1.size();
    for (int i = 0; i < (int) group1.size(); i++) {
        cout << " " << group1[i];
    }
    cout << endl;

    return 0;
}
