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

void solve() {
    int n, x;
    cin >> n >> x;

    int even = 0, odd = 0;
    vector<int> a(n);
    for (int& z : a) {
        cin >> z;
        if ((z & 1)) {
            odd++;
        } else {
            even++;
        }
    } 

    if ((x == n && odd % 2 == 0) || !odd || (x % 2 == 0 && !even)) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
