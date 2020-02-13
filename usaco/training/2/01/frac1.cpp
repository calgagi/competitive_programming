/*
ID: calgagi1
LANG: C++
TASK: frac1
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

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}
bool compare(const ii& lhs, const ii& rhs) {
    double l = (double) lhs.first / (double) lhs.second;
    double r = (double) rhs.first / (double) rhs.second;
    return l < r;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("frac1.in", "r", stdin), *OUT = freopen("frac1.out", "w", stdout); 

    int N;
    cin >> N;

    vector<ii> ans;
    ans.push_back({1, 1});
    ans.push_back({0, 1});

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(j, i) == 1) {
                ans.push_back({j, i});
            } 
        }
    }

    sort(ans.begin(), ans.end(), compare);

    for (auto& p : ans) {
        cout << p.first << "/" << p.second << endl;
    }

    return 0;
}
