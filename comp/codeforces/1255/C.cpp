// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
	
    int n; cin >> n;
    vector<int> counts(n+1, 0);
    vector<vector<int>> adj(n+1);

    int a, b, c;
    forn(i, n-2) {
        cin >> a >> b >> c; 
        counts[a]++; counts[b]++; counts[c]++;
        adj[a].pb(b); adj[a].pb(c);
        adj[b].pb(a); adj[b].pb(c);
        adj[c].pb(a); adj[c].pb(b);
    }
    vector<int> ans(n);
    // First and last #s will be 1 freq
    // 2nd to first and 2nd to last will be 2 freq
    int count1 = 0, count2 = 0;
    // O(n)
    forn(i, n) {
        if (counts[i+1] == 1) {
            ans[0] = i+1;
            swap(ans[0], ans[n-1]);
            count1++;
        } else if (counts[i+1] == 2) {
            ans[1] = i+1;
            swap(ans[1], ans[n-2]);
            count2++;
        }
        if (count1 == 2 && count2 == 2) break;
    }

    // Swap if not adjacent
    if (find(adj[ans[0]].begin(), adj[ans[0]].end(), ans[1]) == adj[ans[0]].end()) swap(ans[1], ans[n-2]);

    vector<bool> seen(n, false);
    seen[ans[0]] = true; seen[ans[1]] = true; seen[ans[n-2]] = true; seen[ans[n-1]] = true;
    fore(i, 2, n-2) {
        for (auto& item : adj[ans[i-1]]) {
            if (!seen[item] && find(adj[ans[i-2]].begin(), adj[ans[i-2]].end(), item) != adj[ans[i-2]].end()) {
                ans[i] = item;
                break;
            }
        }
        seen[ans[i]] = true;
    }
    
    for (auto& item : ans) cout << item << " ";
    cout << endl;

    return 0;
}
