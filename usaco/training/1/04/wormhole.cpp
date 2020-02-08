/*
ID: calgagi1
LANG: C++
TASK: wormhole
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int ans = 0;
vector<int> graph;
vector<ii> worms;
int n;

bool dfs(const vector<int>& assign, vector<int>& seen, int cur) {
    if (seen[cur]) {
        return 1;
    }
    seen[cur] = 1;
    bool result = 0;
    if (graph[cur] != -1) {
        result = dfs(assign, seen, assign[graph[cur]]); 
    }
    seen[cur] = 0;
    return result;
}

void assign_pair(vector<int>& a, int j) {
    if (j < n) {
        if (a[j] != -1) {
            assign_pair(a, j+1);
        } else {
            for (int i = j+1; i < n; i++) {
                if (a[i] == -1) {
                    a[i] = j;
                    a[j] = i;
                    assign_pair(a, j+1);
                    a[i] = -1;
                    a[j] = -1;
                }    
            }
        }
    } else {
        /* cerr << "start: " << endl; */
        /* for (int i = 0; i < n; i++) { */
        /*     cerr << a[i] << " "; */
        /* } */
        /* cerr << endl; */
        vector<int> seen(n, 0);
        for (int i = 0; i < n; i++) {
            if (dfs(a, seen, i)) {
                ans++;
                break;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("wormhole.in", "r", stdin), *OUT = freopen("wormhole.out", "w", stdout); 

    cin >> n;
    worms.resize(n);
    for (auto& p : worms) {
        cin >> p.first >> p.second;
    }

    sort(worms.begin(), worms.end());
    graph.assign(n, -1);
    // create graph edges that must be there
    /* cerr << "WORM LINKS: " << endl; */
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (worms[i].second == worms[j].second && worms[i].first < worms[j].first) {
                graph[i] = j;
                break;
            }
        }
        /* cerr << graph[i] << " "; */
    }
    /* cerr << endl; */

    // find number of ways to assign pairs such that there is a cycle
    vector<int> assign(n, -1);
    assign_pair(assign, 0);

    cout << ans << endl;

    return 0;
}
