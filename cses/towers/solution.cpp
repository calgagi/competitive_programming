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
    vector<int> blocks(n);
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    multiset<int> towers;

    for (int i = 0; i < n; i++) {
        auto tower = towers.upper_bound(blocks[i]);

        if (tower == towers.end()) {
            towers.insert(blocks[i]);
        } 
        else {
            towers.insert(blocks[i]);
            towers.erase(tower);
        }
    }
        
    cout << towers.size() << endl;

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
