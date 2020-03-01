// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    vector<bool> seen(n, 0);
    for (int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        seen[x-1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}
