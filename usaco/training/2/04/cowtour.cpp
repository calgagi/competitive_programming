/*
ID: calgagi1
LANG: C++
TASK: cowtour
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

vector<vector<dd>> mat;
vector<bool> visit;
int n;
vector<ii> pos;

dd longest(int a, int b) {
    dd dx = pos[a].f-pos[b].f, dy = pos[a].s-pos[b].s;
    dd dist = sqrt(dx*dx + dy*dy);
    dd ans = dist, ansa = 0, ansb = 0;

    for (int i = 0; i < n; i++) {
        ansa = max(ansa, mat[a][i]);
    }
    for (int i = 0; i < n; i++) {
        ansb = max(ansb, mat[b][i]);
    }

    return ans + ansb + ansa;
}
                

dd diameter() {
    dd ans = 1e18;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (mat[i][j] == -1) {
                ans = min(ans, longest(i, j));
            }
        }
    }

    return ans;
}

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][k] == -1 || mat[k][j] == -1) {
                    continue;
                }
                mat[i][j] = min((mat[i][j] == -1 ? 1e18 : mat[i][j]), mat[i][k] + mat[k][j]);
            }
        }
    }

    return;
}

void solve() {
    cin >> n;
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i].f >> pos[i].s;
    }

    mat.assign(n, vector<dd>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char connect;
            cin >> connect;
            if (connect == '1') {
                dd dx = pos[i].f-pos[j].f, dy = pos[i].s-pos[j].s;
                mat[i][j] = sqrt(dy*dy + dx*dx);
            } else {
                mat[i][j] = (i == j ? 0 : -1);
            }
        }
    }
    
    floyd_warshall();

    dd ans_already = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans_already = max(ans_already, mat[i][j]);
        }
    }

    dd ans = diameter();

    cout << setprecision(6) << fixed;
    cout << max(ans, ans_already) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("cowtour.in", "r", stdin), *OUT = freopen("cowtour.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
