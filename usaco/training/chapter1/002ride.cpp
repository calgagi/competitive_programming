/*
ID: calgagi1
LANG: C++
TASK: ride
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

const int MOD = 47;

int get_ans(const string& s) {
    int ans = 1;
    for (auto& c : s) {
        ans = (ans * (c - 'A' + 1)) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    freopen("ride.in", "r", stdin); freopen("ride.out", "w", stdout); 

    string comet, group;
    cin >> comet >> group;

    cout << (get_ans(comet) == get_ans(group) ? "GO" : "STAY") << endl;

    return 0;
}
