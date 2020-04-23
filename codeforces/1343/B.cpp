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
    int n;
    cin >> n;

    int d = n/2;
    if ((d & 1)) {
        cout << "NO" << endl;
        return;
    }  

    cout << "YES" << endl;
    for (int i = 1; i < d; i++) {
        cout << i*2 << " ";
    }
    cout << d+n << " ";
    for (int i = 1; i <= d; i++) {
        cout << i*2+1 << " ";
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
