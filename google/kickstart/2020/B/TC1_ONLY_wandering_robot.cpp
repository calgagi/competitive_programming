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
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    
    ii bl = {l+1, d-1}, tr = {r-1, u+1};
    
    dd ans = 0;
    vector<dd> fact;
    fact.push_back(0);
    for (int i = 2; i <= max(w,h); i++) {
         

    while (bl.f <= h && bl.s) {
        
        bl.f++;
        bl.s--;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    cout << fixed << showpoint << setprecision(6);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
