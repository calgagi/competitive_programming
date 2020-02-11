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
    
    const int MAX_M = 250;
    const int MAX = MAX_M*MAX_M*2;

    bool is_bisquare[MAX+1] = {0};

    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            is_bisquare[i*i + j*j] = 1;
        }
    }

    vector<ii> ans;

    for (int i = 0; i <= MAX; i++) {
        if (!is_bisquare[i]) {
            continue;
        }
        int diff = MAX - i;
        for (int j = 1; j <= ceil((double)diff / (double)n); j++) {
            int k;
            for (k = 1; k < n && i+j*k <= MAX; k++) {
                if (!is_bisquare[i + j*k]) {
                    break;
                }
            }
            if (k == n) {
                ans.push_back({j, i});
            }
        }
    }
            
            
    if (ans.size() == 0) {
        cout << "NONE" << endl;
    } else {
        sort(ans.begin(), ans.end());
        for (auto& p : ans) {
            cout << p.second << " " << p.first << endl;
        }
    }

    return 0;
}
