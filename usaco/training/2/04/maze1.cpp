/*
ID: calgagi1
LANG: C++
TASK: maze1
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

vector<ii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    int w, h;
    cin >> w >> h;
    vector<string> g(2*h+1);
    getline(cin, g[0]);
    for (int i = 0; i < 2*h+1; i++) {
        getline(cin, g[i]);
    }

    queue<pair<ii, int>> q;

    for (int i = 1; i < 2*h; i += 2) {
        if (g[i][0] == ' ') {
            q.push({{i, 1}, 1});
        } 
        if (g[i][2*w] == ' ') {
            q.push({{i, 2*w-1}, 1});
        }
    }
            
    for (int i = 1; i < 2*w; i += 2) {
        if (g[0][i] == ' ') {
            q.push({{1, i}, 1});
        } 
        if (g[2*h][i] == ' ') {
            q.push({{2*h-1, i}, 1});
        }
    }       

    vector<vector<bool>> visit(h, vector<bool>(w, 0));

    int ans = 0;

    while (!q.empty()) {
        pair<ii, int> c = q.front();
        q.pop();
        ii p = c.f;
        int d = c.s;

        if (p.f < 0 || p.s < 0 || p.f > 2*h || p.s > 2*w || visit[p.f/2][p.s/2]) {
            continue;
        }

        visit[p.f/2][p.s/2] = 1;
        ans = max(ans, d);

        for (ii& t : dir) {
            if (g[p.f+t.f][p.s+t.s] == ' ') {
                q.push({{p.f+2*t.f, p.s+2*t.s}, d+1});
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
    FILE *IN = freopen("maze1.in", "r", stdin), *OUT = freopen("maze1.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
