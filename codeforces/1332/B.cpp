/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double
 
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const int P = primes.size();
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n, -1);
    for (auto& i : a) {
        cin >> i;
    }
    
    int m = 0;
    for (int p = 0; p < P; p++) {
        bool f = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1 && a[i] % primes[p] == 0) {
                ans[i] = m;
                f = 1;
            } 
        }
        if (f) {
            m++;
        }
    }

    cout << m << endl;
    for (auto& i : ans) {
        cout << i+1 << " ";
    }
    cout << endl;
 
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
