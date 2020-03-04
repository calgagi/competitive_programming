/*
ID: calgagi1
LANG: C++
TASK: breedflip
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
    FILE *IN = freopen("breedflip.in", "r", stdin), *OUT = freopen("breedflip.out", "w", stdout); 

    int n;
    cin >> n;
    string s, g;
    cin >> s >> g;

    int res = 0;
    while (s != g) {
        int idx = 0, str = 0, best = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != g[i]) {
                str++;
            } else {
                str = 0;
            }
            if (str > best) {
                best = str;
                idx = i-str+1;
            }
        }
        for (int i = idx; i < idx+best; i++) {
            s[i] = (s[i]=='H'?'G':'H');
        }
        res++;
        //cerr << s << " " << g << endl;
    }

    cout << res << endl;

    return 0;
}
