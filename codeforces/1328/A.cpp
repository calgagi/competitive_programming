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
        int res = 0, a, b;
        cin >> a >> b;
        if (a == b) {
            res = 0;
        } else if (a < b) {
            res = b-a;
        } else if (a > b) {
            int d = ceil((float)a/(float)b);
            d *= b;
            res = d-a;
        } 
        cout << res << endl;
    }

    return 0;
}
