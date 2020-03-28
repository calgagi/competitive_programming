/*
ID: calgagi1
LANG: C++
TASK: swap
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

bool is_equal(vector<int>& c, vector<int>& cc) {
    for (int i = 0; i < (int) c.size(); i++) {
        if (c[i] != cc[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("swap.in", "r", stdin), *OUT = freopen("swap.out", "w", stdout); 

    int n, k, a1, a2, b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    a1--, b1--;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cows[i] = i+1; 
    }
    
    vector<int> cycle = cows;
    vector<vector<int>> ans;

    do {
        ans.push_back(cows);
        reverse(cows.begin()+a1, cows.begin()+a2);
        reverse(cows.begin()+b1, cows.begin()+b2);
        /* for (auto& c : cows) { */
        /*     cerr << c << " "; */
        /* } */
        /* cerr << endl; */
    } while (!is_equal(cows, cycle));

    k %= ans.size();

    for (int i = 0; i < n; i++) {
        cout << ans[k][i] << endl;
    }

    return 0;
}
