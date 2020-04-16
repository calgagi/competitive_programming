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
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int,int> seen;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (seen[x - a[i]] != 0) {
            cout << i+1 << " " << seen[x - a[i]] << endl;
            f = 1;
            break;
        }
        seen[a[i]] = i+1;
    }
    
    if (!f) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
