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

int n, m, q;
int ans = 0;
vector<ar<int,4>> quad;

void check(vector<int>& x) {
    int ans2 = 0;
    for (auto& z : quad) {
        if (x[z[1]] - x[z[0]] == z[2]) {
            ans2 += z[3];
        }
    }
    ans = max(ans, ans2);

    /* cout << "CHECK: "; */
    /* for (int i = 1; i <= n; i++) { */
    /*     cout << x[i] << " "; */
    /* } */
    /* cout << ans2 << endl; */

    return;
}

void build(vector<int>& x, int i) {
    if (i == n+1) {
        check(x);    
        return;
    }
    for (int j = x[i-1]; j <= m; j++) {
        x[i] = j;
        build(x, i+1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    cin >> n >> m >> q;
    quad.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> quad[i][0] >> quad[i][1] >> quad[i][2] >> quad[i][3];
    }

    vector<int> x(n+1);
    x[0] = 1;
    build(x, 1); 

    cout << ans << endl;

    return 0;
}
