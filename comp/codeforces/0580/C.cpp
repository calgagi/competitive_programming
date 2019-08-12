// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    bool cat[n];
    for (int i = 0; i < n; i++) cin >> cat[i];
    int start = 0;
    vector<vector<int> > graph(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    int r = 0;
    stack<pair<int, int> > s;
    s.push({0, 0});
    vector<bool> seen(n, false);
    while (!s.empty()) {
        int consecutive_cat = s.top().second;
        int node = s.top().first;
        s.pop();
        seen[node] = true;
        consecutive_cat = cat[node] ? consecutive_cat + 1 : 0;
        if (consecutive_cat == m+1) {
            continue;
        }
        if (graph[node].size() == 1 && node != 0) {
            r++;
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            if (!seen[graph[node][i]]) {
                s.push({graph[node][i], consecutive_cat});
            }
        }
        
    }
    cout << r << endl;
    return 0;
}
