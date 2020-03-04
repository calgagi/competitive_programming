/*
ID: calgagi1
LANG: C++
TASK: triangles
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
    FILE *IN = freopen("triangles.in", "r", stdin), *OUT = freopen("triangles.out", "w", stdout); 

    int n;
    cin >> n;
    map<int,vector<int>> x, y;
    vector<ii> pp(n);
    for (int i = 0; i < n; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        x[y1].push_back(x1);
        y[x1].push_back(y1);
        pp[i] = {x1, y1};
    }

    int res = 0;
    for (auto& p : pp) {
        for (auto& x1 : x[p.second]) {
            for (auto& y1 : y[p.first]) {
                res = max(res, abs(p.first-x1)*abs(p.second-y1));
            }
        }
    }

    cout << res << endl;

    return 0;
}
