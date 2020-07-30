/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

void solve() {
    string s;
    cin >> s;

    vector<int> ans;
    ll pre_hash = 0, suf_hash = 0, pos = 1;
    const ll MOD = 1e14 + 7, MULT = 31;

    int n = s.length(); 
    for (int i = 0; i < n-1; i++) {
        pre_hash = (pre_hash + (pos * (1 + s[i] - 'a'))) % MOD;
        suf_hash = (suf_hash * MULT + (1 + s[n-1-i] - 'a')) % MOD;
        pos = (pos * MULT) % MOD;
        if (pre_hash == suf_hash) {
            ans.push_back(i+1);
        }
    }

    for (int l : ans) {
        cout << l << " ";
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
