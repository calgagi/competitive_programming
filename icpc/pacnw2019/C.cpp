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
	
    int n, m; cin >> n >> m;
    unordered_map<int,vector<int>> graph;
    forn(i, m){
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    // BFS
    unordered_map<int,bool> seen;
    queue<pair<int,int>> q;
    q.push({1, 0});
    int max_path = -1;
    while(!q.empty()) {
        int p = q.front().y;
        int from = q.front().x;
        q.pop();
        if (seen.count(from)) continue;
        seen[from] = true;
        if (from == n) {
            max_path = p;
            break;
        }
        for (auto& i : graph[from]) {
            if(!seen.count(i)) q.push({i, p+1});
        }
    }
    cout << max(max_path - 1,0) << endl;

    return 0;
}
