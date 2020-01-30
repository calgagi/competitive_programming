// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

void solve() {
    string s, t, z;
    cin >> s >> t;
    
    int n = s.length();
    // greedy
    int where[n+2][26];
    memset(where, 255, sizeof(where));
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (where[i][j] == -1)
                where[i][j] = where[i+1][j];
        }
        if (i)
            where[i-1][s[i-1]-'a'] = i;
    }

    /* for (int j = 0; j < 26; j++) { */
    /*     for (int i = 0; i < n+2; i++) { */
    /*         cout << where[i][j] << "\t"; */
    /*     } */
    /*     cout << endl; */
    /* } */

    
    int cur = 0, i = 0;
    bool impossible = false;
    while (i < (int) t.length()) {
        int j = 0;
        while (i < (int) t.length() && where[j][t[i]-'a'] != -1) {
            int save_j = j;
            j = where[j][t[i]-'a'];
            i++;
        }

        if (j == 0) {
            impossible = true;
            break;
        } 

        cur++;
    }

    cout << (impossible ? -1 : cur) << endl;

    return;
}
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) solve();


    return 0;
}
