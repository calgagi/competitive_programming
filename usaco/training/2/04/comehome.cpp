/*
ID: calgagi1
LANG: C++
TASK: comehome
*/
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

map<char, vector<pair<char,int>>> graph;
const char barn = 'Z';
map<char, int> dist;
set<char> visit;

void dijkstra() {
    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> q;
    q.push({0, barn});
   
    while (!q.empty()) {
        pair<int,char> u = q.top();
        q.pop();
        
        int d = u.f;
        char w = u.s;
        if (visit.find(w) != visit.end()) {
            continue;
        }

        visit.insert(w);
        dist[w] = d;

        for (pair<char,int> v : graph[w]) {
            q.push({v.s+d, v.f});    
        }
    }

    return;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v;
        cin >> u >> v;
        int d;
        cin >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }    

    dijkstra();
    
    pair<char, int> ans = {'A', INT_MAX};
    for (pair<char,int> p : dist) {
        if (p.f == 'Z') {
            continue;
        }
        if (p.s < ans.s && p.f <= 'Z' && p.f >= 'A') {
            ans = p;
        }
    }

    cout << ans.f << " " << ans.s << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("comehome.in", "r", stdin), *OUT = freopen("comehome.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
