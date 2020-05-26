/*
ID: calgagi1
LANG: C++
TASK: concom
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

const int COMP = 100;
vector<ii> ans;
vector<int> visited, ownage;
vector<vector<ii>> graph(COMP);

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }
    visited[cur] = 1;

    for (ii& edge : graph[cur]) {
        ownage[edge.f] += edge.s;
        if (ownage[edge.f] >= COMP/2) {
            dfs(edge.f);
        }
    }

    return;
}

void find_own(int cur) {
    visited.assign(COMP, 0);
    ownage.assign(COMP, 0);

    dfs(cur);

    for (int i = 0; i < COMP; i++) {
        if (i != cur && ownage[i] >= COMP/2) {
            ans.push_back({cur, i});
        }
    }

    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("concom.in", "r", stdin), *OUT = freopen("concom.out", "w", stdout); 

    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        int i, j, p;
        cin >> i >> j >> p;
        i--, j--;
        graph[i].push_back({j, p}); 
    }

    for (int i = 0; i < COMP; i++) {
        find_own(i);
    }

    sort(ans.begin(), ans.end());
    for (ii& a : ans) {
        cout << a.f+1 << " " << a.s+1 << endl;
    }

    return 0;
}
