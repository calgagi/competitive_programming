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

void solve() {
    int n, k;
    cin >> n >> k;
    
    int j = 1, pos1 = n-2, pos2 = n-1, i = 1;
    while (j+i <= k) {
        j += i;
        i++;
        pos1--;
    }
    while (j < k) {
        pos2--;
        j++;
    }
    for (int i = 0; i < n; i++) {
        if (i == pos1 || i == pos2) {
            cout << "b";
        } else {
            cout << "a";
        }
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
