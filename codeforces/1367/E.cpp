/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }

    int ans = 0;
    /* cout << "START" << endl; */
    for (int cycle_length = 1; cycle_length <= k; cycle_length++) {
        if (k % cycle_length != 0) {
            continue;
        }         
        /* cout << "testing: " << cycle_length << endl; */
        for (int cycles = 1; cycles <= n; cycles++) {
            int beads_required = cycle_length;
            for (int i = 0; i < 26; i++) {
                beads_required -= (cnt[i] / cycles); 
            }
            if (beads_required <= 0) {
                ans = max(cycles*cycle_length, ans);
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
