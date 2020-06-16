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
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    for (int& x : b) {
        cin >> x;
    }

    int n = s.length();
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }

    string ans(m, ' ');

    for (int letter = 25; letter >= 0; letter--) {

        int count = 0;
        for (int i = 0; i < m; i++) {
            if (b[i] == 0) {
                count++;
            }
        }

        if (cnt[letter] < count) {
            continue;
        }

        vector<int> zeros;
        for (int i = 0; i < m; i++) {
            if (b[i] == 0) {
                ans[i] = (char) letter + 'a';
                zeros.push_back(i);
                b[i] = -1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (b[i] != -1) {
                for (int& x : zeros) {
                    b[i] -= abs(i - x);
                }
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
