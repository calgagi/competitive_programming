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
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    const int M = 51;
    
    int c, n, m;
    cin >> c >> n >> m;
    vector<ll> C(n);
    queue<ll> q;
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        q.push(C[i]);
    }
    
    ll d = 0;
    ll e = n;
    vector<ll> ans(M, 0);
    for (int day = 0; day < M; day++) {
        queue<ll> new_q;
        while (!q.empty()) {
            ll a = q.front();
            q.pop();
            if (a > c) {
                d += 2; 
                e -= 1;
            } else {
                new_q.push(a*2);
            }
        }
        q = new_q;
        ans[day] = d+e;
        d *= 2LL;
    }

    /* for (int i = 0; i < M; i++) { */
    /*     cout << ans[i] << " "; */
    /* } */
    /* cout << endl; */

    // print answer
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        /* cout << x << endl; */
        cout << ans[x] << endl;
    }


    return 0;
}
