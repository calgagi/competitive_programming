// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

const int MAXR = 2e5 + 10;

void solve() {
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    int diff_count[MAXR] = {0};
    int bias = MAXR / 2;

    ll cnt0 = 0, cnt1 = 0, in = 0;
    if (x == 0) in++; 
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt0++;
        if (s[i] == '1') cnt1++;
        if (cnt0 - cnt1 == x) {
            in++; 
        }
        diff_count[cnt0-cnt1+bias]++;
    }

    ll tot_diff = cnt0 - cnt1;
    // edge case 
    if (tot_diff == 0) {
        if (in != 0) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        int ans = 0;
        for (int i = 0; i < MAXR; i++) {
            if (diff_count[i] != 0) {
                int delta = i - bias; 
                if ((x+delta)*tot_diff >= 0 && (x + delta) % tot_diff == 0)
                    ans += diff_count[i]; 
            }
        }
        cout << ans << endl;
    }

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
