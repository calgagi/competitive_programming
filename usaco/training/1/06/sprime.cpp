/*
ID: calgagi1
LANG: C++
TASK: sprime
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

int N;
vector<ll> ans;

bool is_prime(string s) {
    ll i = stoll(s);
    for (ll j = 2; j*j <= i; j++) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

void dfs(string s) {
    int l = s.length();
    bool p = is_prime(s);
    if (p == false) {
        return;
    }
    if (l == N) {
        ans.push_back(stoll(s));
        return;
    }
    dfs(s + '1');
    dfs(s + '3');
    dfs(s + '7');
    dfs(s + '9');
}
        
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("sprime.in", "r", stdin), *OUT = freopen("sprime.out", "w", stdout); 

    cin >> N;

    dfs("2");
    dfs("3");
    dfs("5");
    dfs("7");
    dfs("9");

    sort(ans.begin(), ans.end());

    for (auto& i : ans) {
        cout << i << endl;
    }

    return 0;
}
