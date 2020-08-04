/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long

int n, q;
const int MAX_N = 2e5, MAX_POW = 31;
int lift[MAX_N][MAX_POW];

void build() {
    for (int power = 1; power < MAX_POW; power++) {
        for (int planet = 0; planet < n; planet++) {
            lift[planet][power] = lift[lift[planet][power-1]][power-1]; 
        }        
    }
    return;
}
    
void query(int where, int dist) {
    int power = 0;
    while (dist) {
        if ((dist & 1)) {
            where = lift[where][power];
        }
        dist >>= 1;
        power++;
    }

    cout << where+1 << endl;
    return;
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> lift[i][0];
        lift[i][0]--;
    }

    build();

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        query(x, k);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
