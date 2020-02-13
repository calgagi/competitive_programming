/*
ID: calgagi1
LANG: C++
TASK: sort3
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("sort3.in", "r", stdin), *OUT = freopen("sort3.out", "w", stdout); 

    int n;
    cin >> n;

    vector<int> medal(n);
    int count[3] = {0};
    for (auto& m : medal) {
        cin >> m;
        m--;
        count[m]++;
    }

    int bad[3][3] = {0};
    for (int i = 0, j = 0, k = 0; i < n; i++, j++) { 
        while (j == count[k]) {
            j = 0;
            k++;
        }
        if (medal[i] != k) {
            bad[k][medal[i]]++; 
        }
    }

    /* cerr << "BEFORE" << endl; */
    /* for (int i = 0; i < 3; i++) { */
    /*     cerr << i << "," << count[i] << ": "; */
    /*     for (int j = 0; j < 3; j++) { */
    /*         cerr << bad[i][j] << " "; */
    /*     } */
    /*     cerr << endl; */
    /* } */

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                continue;
            }
            int swp = min(bad[i][j], bad[j][i]);
            bad[i][j] -= swp;
            bad[j][i] -= swp;
            ans += swp;
        }
    }

    for (int i = 1; i < 3; i++) {
        ans += 2 * bad[0][i]; 
    }
         
        
    /* cerr << "AFTER" << endl; */
    /* for (int i = 0; i < 3; i++) { */
    /*     cerr << i << "," << count[i] << ": "; */
    /*     for (int j = 0; j < 3; j++) { */
    /*         cerr << bad[i][j] << " "; */
    /*     } */
    /*     cerr << endl; */
    /* } */

    cout << ans << endl;

    return 0;
}
