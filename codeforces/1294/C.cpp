// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

const int MAX_N = 1e9 + 1;
vector<bool> prime;

void sieve() { 
    int s = sqrt(MAX_N);
    prime.assign(s+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= s; i++) {
        if (prime[i]) {
            for (int j = i+i; j <= s; j += i) {
                prime[j] = false;
            }
        }
    }
    return;
}

void solve() {
    ll n;
    cin >> n;

    // find all factors of n
    int sn = sqrt(n);
    for (int i = 2; i <= sn; i++) {
        if (n % i == 0) {
            int a = n/i;
            int sa = sqrt(a);
            // factors = i, j, a/j
            // find factors of a
            for (int j = 2; j <= sa; j++) {
                if (j == i) continue;
                if (a % j == 0) {
                    int aj = a / j;
                    if (aj == j || aj == i) continue;
                    cout << "YES" << endl;
                    cout << i << " " << j << " " << aj << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl; 

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    //sieve();

    int t;
    cin >> t;
    while (t--)
        solve();
     

    return 0;
}
