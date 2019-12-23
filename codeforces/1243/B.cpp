// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    unordered_map<char,int> see;
    for (auto& c : s) see[c]++;
    for (auto& c : t) see[c]++;
    for (auto& p : see)
        if (p.second % 2 == 1) {
            cout << "No\n";
            return;
        }
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            bool flag = 0;
            for (int j = i+1; j < n; j++) {
                if (s[j] != t[j]) {
                    if (s[j] == s[i]) {
                        swap(s[j], t[i]);
                        ans.push_back({j, i});
                        flag = 1;
                        break;
                    } else if (t[j] == t[i]) {
                        swap(s[i], t[j]);
                        ans.push_back({i, j});
                        flag = 1;
                        break;
                    }
                }
            }       
            if (flag) continue;
            for (int j = i+1; j < n; j++) {
                if (s[j] != t[j]) {
                    if (t[j] == s[i]) {
                        swap(s[j], t[j]);
                        // Now, s[j] == s[i]
                        swap(s[j], t[i]);
                        ans.push_back({j, j});
                        ans.push_back({j, i});
                        break;
                    } else if (s[j] == t[i]) {
                        swap(s[j], t[j]);
                        // Now, t[j] == t[i]
                        swap(s[i], t[j]);
                        ans.push_back({j, j});
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }
    if (2*n >= (int)ans.size()) {
        cout << "YES\n";
        cout << ans.size() << endl;
        for (auto& p : ans) {
            cout << p.first+1 << " " << p.second+1 << endl;
        }
    } else {
        cout << "NO\n";
    }
    return;
}
            


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int k; cin >> k;
    while (k--) solve();

    return 0;
}
