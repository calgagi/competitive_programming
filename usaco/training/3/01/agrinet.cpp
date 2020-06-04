/*
ID: calgagi1
LANG: C++
TASK: agrinet
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

vector<int> sz, link;
ll ans = 0;

int find(int a) {
    while (link[a] != a) {
        a = link[a];
    }
    return a;
}

void unite(int a, int b, int val) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }

    ans += val;

    if (sz[b] < sz[a]) {
        swap(a, b);
    }

    sz[b] += sz[a];
    link[a] = b;

    return;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<ar<int,3>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edges.push_back({mat[i][j], i, j});
        }
    }

    link.resize(n), sz.resize(n);
    for (int i = 0; i < n; i++) {
        sz[i] = 1;
        link[i] = i;
    }

    sort(edges.begin(), edges.end());

    for (ar<int,3>& e : edges) {
        unite(e[2], e[1], e[0]);
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("agrinet.in", "r", stdin), *OUT = freopen("agrinet.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
