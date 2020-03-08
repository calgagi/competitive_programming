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
    
    if (n == 1) {
        cout << 1 << endl;
    } else if (n <= 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        vector<int> ans(n, 0);
        for (int i = 1, j = 1; i <= n; i++, j = (j+2)%n) {
            if (j == 1 && ans[j] != 0) {
                j--;
            }
            ans[j] = i;
        }
        for (auto& i : ans) {
            cout << i << " ";
        } 
        cout << endl;
    }

    return 0;
}
