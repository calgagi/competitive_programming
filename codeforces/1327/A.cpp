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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if ((n&1) != (k&1) || k*k > n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
