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

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t;
    cin >> t;

    while (t--) {
        int n, m; 
        cin >> n >> m;

        int ans;
        if (!(n & 1) || !(m & 1)) {
            ans = (n*m)/2;
        } else {
            ans = ((n-1)*m)/2 + (m+1)/2;
        }
            
        cout << ans << endl;
    }

    return 0;
}
