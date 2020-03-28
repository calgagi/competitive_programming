/*
ID: calgagi1
LANG: C++
TASK: cereal
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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("cereal.in", "r", stdin), *OUT = freopen("cereal.out", "w", stdout); 

    int n, m;
    cin >> n >> m;
    vector<ii> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
        c[i].first--, c[i].second--;
    }

    // new strat: work backwards
    vector<int> ans(n);
    vector<ii> q(m, {INT_MAX, INT_MAX});
    int cur = 0;
    for (int i = n-1; i >= 0; i--) {
        ii x = {i, 1};
        int d = c[x.f].f;
        /* cerr << "start: " << i << endl; */
        // evict
        do {
            ii p = q[d];
            /* cerr << p.f << " " << p.s << endl; */
            q[d] = x;
            x = p;
            /* cerr << "x: " << x.f << " " << x.s << endl; */
            if (x.f == INT_MAX || x.s == 2) {
                break;
            }
            d = c[x.f].s;
            x.s = 2;
        } while (x.f < q[d].f);
        if (x.f == INT_MAX) {
            cur++;
        }
        ans[i] = cur;
    }


    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
