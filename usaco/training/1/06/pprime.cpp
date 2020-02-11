/*
ID: calgagi1
LANG: C++
TASK: pprime
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

unordered_set<string> seen;
ll a, b;
vector<ll> primes;

bool is_prime(ll i) {
    for (int j = 2; j*j <= i; j++) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

void dfs(string s) {
    ll i = stoll(s);
    if (i > b || s.length() > 9 || seen.count(s)) {
        return;
    }
    if (i >= a && is_prime(i)) {
        primes.push_back(i);
    } 
    seen.insert(s);
    for (char j = '0'; j <= '9'; j++) {
        dfs(j + s + j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("pprime.in", "r", stdin), *OUT = freopen("pprime.out", "w", stdout); 

    cin >> a >> b;

    for (int i = 0; i <= 9; i++) {
        dfs(to_string(i));
        dfs(to_string(i) + to_string(i));
    }

    sort(primes.begin(), primes.end());
    for (auto& p : primes) {
        cout << p << endl;
    }
            
    return 0;
}
