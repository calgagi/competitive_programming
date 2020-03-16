// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

vector<vector<pair<ll,int>>> groups;
vector<vector<ll>> tables;
int k;

map<vector<int>, ll> dp;

void reset_groups() {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].size(); j++) {
            groups[i][j].second = k;
        }
    }
    return;
}

ll calculate(vector<int>& t) {
    ll res = 0;
    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    vector<vector<ll>> ttg(groups.size());
    for (int i = 0; i < t.size(); i++) {
        ttg[t[i]].insert(ttg[t[i]].begin(), tables[i].begin(), tables[i].end());
    }
    for (int i = 0; i < ttg.size(); i++) {
        sort(ttg[i].begin(), ttg[i].end(), greater<ll>());
        int j = 0, k = 0;
        for ( ; k < ttg[i].size() && j < groups[i].size(); k++) {
            if (groups[i][j].second) {
                groups[i][j].second--;
                res += groups[i][j].first * ttg[i][k];
            } else {
                k--;
                j++;
            }
        }
        if (j < ttg[i].size() && j == groups[i].size()) {
            return -1;
        }
    }
    return res;
}

ll dfs(vector<int>& cur, int t) {
    if (dp.find(cur) != dp.end()) {
        return dp[cur];
    }
    ll res = -1;
    if (t == groups.size()) {
        return -1;
    }
    bool ready = 1;
    for (int i = 0; i < cur.size(); i++) {
        if (cur[i] != -1) {
            continue;
        }
        ready = 0;
        cur[i] = t;
        res = max({res, dfs(cur, t), dfs(cur, t+1)});
        cur[i] = -1;
    }
    if (ready) {
        res = calculate(cur);
        reset_groups();
    }
    dp[cur] = res;
    return res;
}

void solve() {
    dp.clear();
    int m, n, t;
    cin >> m >> n >> t;
    groups.assign(m, vector<pair<ll,int>>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> groups[i][j].first;
        }
        sort(groups[i].begin(), groups[i].end(), greater<pair<ll,int>>());
    }
    tables.assign(t, vector<ll>());
    for (int i = 0; i < t; i++) {
        int x; 
        cin >> x;
        tables[i].resize(x);
        for (int j = 0; j < x; j++) {
            cin >> tables[i][j];
        }
        sort(tables[i].begin(), tables[i].end(), greater<ll>());
    }
    cin >> k;
    for (auto& v : groups) {
        for (auto& x : v) {
            x.second = k;
        }
    }
    vector<int> cur(t, -1);
    ll res = dfs(cur, 0);
    cout << res << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}

