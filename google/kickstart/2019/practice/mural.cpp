/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int solve() {
    int n;
    cin >> n;
    string val;
    cin >> val;
    
    int cur_val = 0;
    for (int i = 0; i < (n+1)/2; i++) {
        cur_val += val[i]-'0';
    }
    int res = cur_val;
    for (int i = (n+1)/2; i < n; i++) {
        cur_val -= val[i-(n+1)/2]-'0';
        cur_val += val[i]-'0';
        res = max(res, cur_val);
    }
    return res; 
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) { 
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }

    return 0;
}
