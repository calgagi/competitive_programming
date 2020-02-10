/*
ID: calgagi1
LANG: C++
TASK: ariprog
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
    FILE *IN = freopen("ariprog.in", "r", stdin), *OUT = freopen("ariprog.out", "w", stdout); 

    int n, m;
    cin >> n >> m;
    
    set<int> bisquares;
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            bisquares.insert(i*i + j*j);
        }
    }

    vector<ii> ans;
    
    for (auto start = bisquares.begin(); start != bisquares.end(); start++) {
        auto next = start;
        next++;
        while (next != bisquares.end()) {
            int diff = *next  - *start;
            int i = 1, ddiff = diff;
            for (; i < n; i++) {
                if (!bisquares.count(ddiff+*start)) {
                    break;
                }
                ddiff += diff;
            }
            if (i == n) {
                ans.emplace_back(diff, *start);
            }
            next++;
        }
    }
                
    sort(ans.begin(), ans.end());

    for (auto& p : ans) {
        cout << p.second << " " << p.first << endl;
    }

    return 0;
}
