// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

const int MAX = 501;
ll dist[MAX][MAX];
const ll M = (ll)INT_MAX*(ll)MAX;
int n;

void floyd_warshalls() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    return;
}
            

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int m, q;
    cin >> n >> m >> q;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = M;
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (dist[a][b] > c) {
            dist[a][b] = dist[b][a] = c;
        }
    }  

    floyd_warshalls();

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (dist[a][b]==M?-1:dist[a][b]) << endl;
    }

    return 0;
}
