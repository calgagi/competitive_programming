/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long
#define double double double
#define ulong unsigned long long
#define ii pair<int, int>
#define ll pair<long long, long long>
#define ar array
#define f first
#define s second
 
long lcm(long a, long b) {
    return (a*b)/__gcd(a, b);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long l = 1;
    int num_twos = -1;
    for (int i = 0; i < n; i++) {
        l = lcm(a[i], l);

        int twos = 0;
        while (!(a[i] & 1)) {
            a[i] /= 2;
            twos++;
        }
        if (num_twos == -1) {
            num_twos = twos;
        }

        if (twos != num_twos) {
            cout << 0 << endl;
            return;
        }
        if (l > 2LL*m) {
            cout << 0 << endl;
            return;
        }
    }
 
    l /= 2;
    int ans = m / l;
    cout << (ans+1) / 2 << endl;
 
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }
 
    return 0;
}
