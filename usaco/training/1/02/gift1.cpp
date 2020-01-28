/*
ID: calgagi1
LANG: C++
TASK: gift1
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
    freopen("gift1.in", "r", stdin); freopen("gift1.out", "w", stdout); 

    int n;
    cin >> n;
    unordered_map<string,int> pti;
    vector<string> ppl(n);
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        ppl[i] = s;
        pti[s] = i;
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int money, num_p, i_p = pti[s];
        cin >> money >> num_p;
        int per_p;
        if (num_p != 0) {
            per_p = money / num_p;
            ans[i_p] += (money % num_p);
        }
        ans[i_p] -= money;
        for (int j = 0; j < num_p; j++) {
            string to;
            cin >> to;
            ans[pti[to]] += per_p;
        }
    }
     
    for (int i = 0; i < n; i++) {
        cout << ppl[i] << " " << ans[pti[ppl[i]]] << endl;
    }

    return 0;
}
