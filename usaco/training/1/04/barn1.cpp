/*
ID: calgagi1
LANG: C++
TASK: barn1
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
    FILE *IN = freopen("barn1.in", "r", stdin), *OUT = freopen("barn1.out", "w", stdout); 

    int m, s, c;
    cin >> m >> s >> c;
    int stalls[s] = {0};
    int mi = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        x--;
        mi = min(mi, x);
        mx = max(mx, x);
        stalls[x] = 1;
    }

    // Find empty spots
    vector<int> e;
    int start = 0;
    while (stalls[start] != 1) start++;
    while (start < s) {
        int end = start+1;
        while (end < s && stalls[end] != 1) end++;
        if (end >= s) break;
        if (end-start-1 != 0) {
            e.push_back(end-start-1);
        }
        start = end;
    } 

    sort(e.begin(), e.end(), greater<int>());

    // With just one board:
    int ans = mx-mi+1;
    for (int i = 2; i <= m && i-2 < (int) e.size(); i++) {
        ans -= e[i-2];
    }

    cout << ans << endl;

    return 0;
}
