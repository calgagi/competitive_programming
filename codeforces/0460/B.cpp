// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int s(int i) {
    int res = 0;
    while (i) {
        res += i % 10;
        i /= 10;
    }
    return res;
}

const int MAX = 1e9 - 1; 

int get_pow(ll j, int e) {
    ll res = j;
    for (int i = 1; i < e; i++) {
        if (res * j <= MAX) {
            res *= j;
        } else {
            return -1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    ll a, b, c;
    cin >> a >> b >> c;

    vector<ll> ans;


    for (int i = 1; i <= 81; i++) {
        ll d = b * get_pow(i, a) + c;
        if (d <= MAX && d > 0 && s(d) == i) {
            ans.push_back(d);
        }
    }
        
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
