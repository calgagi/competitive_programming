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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }

    int where = n+1;
    vector<int> ans(m);
    for (int i = m-1; i >= 0; i--) {
        where = max(where-l[i], i+1);
        ans[i] = where;
    }

    /* for (int i = 0; i < m; i++) { */
    /*     cout << ans[i] << " "; */
    /* } */
    /* cout << endl; */

    if (ans[0] != 1 || ans[m-1]+l[m-1]-1 != n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m-1; i++) {
        if (ans[i]+l[i]-1 < ans[i+1]-1 || ans[i] >= ans[i+1] || ans[i]+l[i]-1 > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    /* // Check if impossible */
    /* ll tot = 0; */
    /* for (int i = 0; i < m; i++) { */
    /*     tot += l[i]; */
    /*     if (l[i] > n-i) { */
    /*         cout << -1 << endl; */
    /*         return 0; */
    /*     } */
    /* } */
    /* if (tot < n) { */
    /*     cout << -1 << endl; */
    /*     return 0; */
    /* } */

    /* // strat: Increase where by 1 until you need to fill up rest of n */
    /* ll where = 0; */ 
    /* for (int i = 0; i < m; i++) { */
    /*     cout << where+1 << " "; */
    /*     ll rest_of_interval = n-where-l[i]; */
    /*     tot -= l[i]; */
    /*     if (rest_of_interval < tot) { */
    /*         where++; */
    /*     } else { */
    /*         where = n-tot; */
    /*     } */
    /* } */   
    /* cout << endl; */

    return 0;
}
