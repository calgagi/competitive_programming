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

const dd PI = 3.14159265359;

void solve() {
    int n;
    cin >> n;

    int num_sides = 2*n;

    dd apothem = 1.0 / (2*tan(PI/num_sides));

    cout << 2*apothem << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 

    cout << fixed << setprecision(10);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
